#ifndef SHAPES_INCLUDE_SPHERE_H
#define SHAPES_INCLUDE_SPHERE_H

#include "i_shape.h"

namespace ray_tracer {
namespace shapes {

class Sphere : public IShape {
 private:
  Sphere() = default;
  Sphere(Transform transformation) : IShape(transformation){};
  Sphere(const Transform& transformation,
         const std::shared_ptr<Material>& material)
      : IShape(transformation, material){};

 protected:
  Vector local_normal_at(const Point& point) const override;
  std::optional<const Intersections> local_intersect(
      const Ray& ray) const override;

 public:
  template <typename... T>
  static std::shared_ptr<const IShape> create(T&&... args) {
    return std::shared_ptr<const IShape>(
        new const Sphere(std::forward<T>(args)...));
  };
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
