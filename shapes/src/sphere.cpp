#include "shapes/sphere.h"

namespace ray_tracer {
namespace shapes {

std::optional<const Intersections> Sphere::intersect(const Ray& ray) const {
  const auto sphere_to_ray = ray.origin - Point(0., 0., 0.);
  const auto a = dot(ray.direction, ray.direction);
  const auto b = 2 * dot(ray.direction, sphere_to_ray);
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

std::shared_ptr<Shape> Sphere::create() {
  return std::shared_ptr<Shape>(new Sphere());
};

}  // namespace shapes
}  // namespace ray_tracer
