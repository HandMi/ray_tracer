#include "world/world.h"
#include "core/color.h"
#include "core/transform.h"
#include "light/point_light.h"
#include "shapes/intersection.h"
#include "shapes/material.h"
#include "shapes/sphere.h"
#include <numeric>

namespace ray_tracer {

World World::Default() {
  auto mat = shapes::Material::create(Color{0.8, 1.0, 0.6});
  mat->diffuse = 0.7;
  mat->specular = 0.2;
  const auto transform = Identity().scale(0.5, 0.5, 0.5);

  const auto s1 = shapes::Sphere::create(Identity(), mat);
  const auto s2 = shapes::Sphere::create(transform);
  auto light =
      std::make_unique<PointLight>(Point{-10., 10., -10.}, Color{1., 1., 1.});
  LightList light_list;
  light_list.push_back(std::move(light));

  return World(std::move(light_list), {s1, s2});
}

shapes::IntersectionList World::intersect(const Ray& ray) const {
  shapes::IntersectionList intersection_list{};
  for (const auto& shape : shapes) {
    const auto intersections = shape->intersect(ray);
    intersection_list.append(intersections);
  }
  intersection_list.sort();
  return intersection_list;
}

Color World::shade(const shapes::Hit& hit) const {
  return std::accumulate(
      lights.begin(), lights.end(), Color{},
      [&](const Color& sum, const auto& light) {
        return sum +
               light->lighting(hit.object->get_material(), hit.point,
                               hit.eye_vector, hit.normal,
                               light->intensity_at(*this, hit.over_point));
      });
}

Color World::color_at(const Ray& ray) const {
  auto intersection_list = intersect(ray);
  const auto optional_hit = intersection_list.hit_candidate();
  if (optional_hit.has_value()) {
    const auto hit = prepare_hit(optional_hit.value(), ray);
    return shade(hit);
  }
  return Colors::Black;
}

bool World::is_shadowed(const Point& point, const Point& light_position) const {
  auto v = light_position - point;
  const auto distance = v.length();
  v.normalize();
  const auto ray = Ray{point, v};
  auto intersection_list = intersect(ray);
  const auto opt_hit = intersection_list.hit_candidate();
  if (opt_hit.has_value() && opt_hit->t < distance) {
    return true;
  }
  return false;
}
}  // namespace ray_tracer
