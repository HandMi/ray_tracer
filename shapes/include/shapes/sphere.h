#ifndef SHAPES_INCLUDE_SPHERE_H
#define SHAPES_INCLUDE_SPHERE_H

#include "shape.h"

namespace ray_tracer {
namespace shapes {

class Sphere : public Shape {
 private:
  Sphere() = default;

 public:
  std::optional<const Intersections> intersect(const Ray& ray) const override;
  static std::shared_ptr<Shape> create();
};

}  // namespace objects
}  // namespace ray_tracer

#endif
