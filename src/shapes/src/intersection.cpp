#include "shapes/intersection.h"
#include "light/ray.h"
#include "shapes/i_shape.h"
#include <algorithm>

namespace ray_tracer {
namespace shapes {

void IntersectionList::append(
    const std::optional<const Intersections>& intersections) {
  if (intersections.has_value()) {
    data.insert(data.end(), intersections->begin(), intersections->end());
  }
}

void IntersectionList::insert(const Intersection& intersection) {
  data.push_back(intersection);
}

void IntersectionList::sort() {
  std::sort(
      data.begin(), data.end(),
      [](const Intersection& a, const Intersection& b) { return a.t < b.t; });
}

std::optional<Intersection> IntersectionList::hit_candidate() {
  sort();
  const auto hiterator = std::lower_bound(
      data.begin(), data.end(), 0.,
      [](const Intersection& a, Decimal b) { return a.t < b; });
  return hiterator != data.end() ? std::optional<Intersection>(*hiterator)
                                 : std::nullopt;
}

Hit prepare_hit(const Intersection& intersection, const Ray& ray) {
  Hit hit{};
  hit.object = intersection.object;
  hit.point = ray.position(intersection.t);
  hit.eye_vector = -ray.direction;
  hit.normal = intersection.object->normal_at(hit.point);
  if (dot(hit.normal, hit.eye_vector) < 0) {
    hit.inside = true;
    hit.normal = -hit.normal;
  } else {
    hit.inside = false;
  }
  hit.over_point = hit.point + hit.normal * EPSILON;
  return hit;
}
}  // namespace shapes
}  // namespace ray_tracer
