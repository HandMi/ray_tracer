#ifndef SHAPES_INCLUDE_SPHERE_H
#define SHAPES_INCLUDE_SPHERE_H

#include "shape.h"

namespace ray_tracer {
namespace shapes {

class Sphere : public Shape {
 private:
  Sphere() = default;
  Sphere(Transform transformation) { set_transform(transformation); };

 public:
  std::optional<const Intersections> intersect(const Ray& ray) const override;
  template <typename... T>
  static std::shared_ptr<Shape> create(T&&... args) {
    return std::shared_ptr<Shape>(new Sphere(std::forward<T>(args)...));
  };
  ;
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
