#include "shapes/sphere.h"

namespace ray_tracer {
namespace shapes {

std::optional<const Intersections> Sphere::intersect(const Ray& ray) const {
  const auto transformed_ray = transformation_inverse * ray;
  const auto sphere_to_ray = transformed_ray.origin - Point(0., 0., 0.);
  const auto a = dot(transformed_ray.direction, transformed_ray.direction);
  const auto b = 2 * dot(transformed_ray.direction, sphere_to_ray);
  const auto c = dot(sphere_to_ray, sphere_to_ray) - 1.;
  const auto discriminant = b * b - 4 * a * c;
  if (discriminant < 0) {
    return std::nullopt;
  } else {
    const auto s = std::sqrt(discriminant);
    return std::vector<Intersection>{{(-b - s) / (2 * a), shared_from_this()},
                                     {(-b + s) / (2 * a), shared_from_this()}};
  }
}
Vector Sphere::normal_at(const Point& point) const {
  const auto object_point = transformation_inverse * point;
  const auto object_normal = object_point - Point{0., 0., 0.};
  auto world_normal = transformation_inverse.T() * object_normal;
  // This is hacky
  world_normal(3) = 0.;
  world_normal.normalize();
  return world_normal;
}
}  // namespace shapes
}  // namespace ray_tracer
