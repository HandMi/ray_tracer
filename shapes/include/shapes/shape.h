#ifndef SHAPES_INCLUDE_SHAPE_H
#define SHAPES_INCLUDE_SHAPE_H

#include "intersection.h"
#include "rays/ray.h"
#include <optional>

namespace ray_tracer {
namespace shapes {

class Intersection;

using Intersections = std::vector<Intersection>;

class Shape : public std::enable_shared_from_this<Shape> {
 public:
  virtual std::optional<const Intersections> intersect(const Ray& ray) const = 0;
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
