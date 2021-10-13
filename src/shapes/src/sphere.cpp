#include "shapes/sphere.h"

namespace ray_tracer {
namespace shapes {

std::optional<const Intersections> Sphere::local_intersect(
    const Ray& local_ray) const {
  const auto sphere_to_ray = local_ray.origin - Point(0., 0., 0.);
  const auto a = dot(local_ray.direction, local_ray.direction);
  const auto b = 2 * dot(local_ray.direction, sphere_to_ray);
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
Vector Sphere::local_normal_at(const Point& local_point) const {
  const auto local_normal = local_point - Point{0., 0., 0.};
  return local_normal;
}
}  // namespace shapes
}  // namespace ray_tracer
