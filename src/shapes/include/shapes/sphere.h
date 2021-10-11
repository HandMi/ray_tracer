#ifndef SHAPES_INCLUDE_SPHERE_H
#define SHAPES_INCLUDE_SPHERE_H

#include "shape.h"

namespace ray_tracer {
namespace shapes {

class Sphere : public Shape {
 private:
  Sphere() = default;
  Sphere(Transform transformation) : Shape(transformation){};
  Sphere(const Transform& transformation, const std::shared_ptr<Material>& material)
      : Shape(transformation, material){};

 public:
  std::optional<const Intersections> intersect(const Ray& ray) const override;
  Vector normal_at(const Point& point) const override;
  template <typename... T>
  static std::shared_ptr<const Shape> create(T&&... args) {
    return std::shared_ptr<const Shape>(new const Sphere(std::forward<T>(args)...));
  };
};

}  // namespace shapes
}  // namespace ray_tracer

#endif