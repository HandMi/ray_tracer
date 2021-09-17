#ifndef SHAPES_INCLUDE_SHAPE_H
#define SHAPES_INCLUDE_SHAPE_H

#include "core/transform.h"
#include "core/tuple.h"
#include "intersection.h"
#include "rays/ray.h"
#include <optional>

namespace ray_tracer {
namespace shapes {

class Intersection;

using Intersections = std::vector<Intersection>;

class Shape : public std::enable_shared_from_this<Shape> {
 protected:
  Transform transformation_inverse{Identity()};

 public:
  virtual std::optional<const Intersections> intersect(const Ray& ray) const = 0;
  virtual Vector normal_at(const Point& point) const = 0;
  void set_transform(Transform transformation) {
    transformation_inverse = transformation.Inv();
  }
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
