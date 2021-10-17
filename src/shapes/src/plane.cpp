#include "shapes/plane.h"

namespace ray_tracer {
namespace shapes {
std::optional<const Intersections> Plane::local_intersect(
    const Ray& local_ray) const {
  if (std::abs(local_ray.direction.y()) < EPSILON) {
    return std::nullopt;
  } else {
    const auto t = -local_ray.origin.y() / local_ray.direction.y();
    return std::vector<Intersection>{{t, shared_from_this()}};
  }
}
Vector Plane::local_normal_at(const Point& local_point) const {
  return {0., 1., 0.};
}
}  // namespace shapes
}  // namespace ray_tracer
