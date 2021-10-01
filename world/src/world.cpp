#include "world/world.h"
#include "core/color.h"
#include "core/transform.h"
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
  const auto light = PointLight{{-10., 10., -10.}, {1., 1., 1.}};
  std::vector<PointLight> lights{light};

  return World(lights, {s1, s2});
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
  return std::accumulate(lights.begin(), lights.end(), Color{},
                         [&hit](const Color& sum, const PointLight& light) {
                           return sum + hit.object->lighting(light, hit.point,
                                                             hit.eye_vector,
                                                             hit.normal);
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
}  // namespace ray_tracer
