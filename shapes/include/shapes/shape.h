#ifndef SHAPES_INCLUDE_SHAPE_H
#define SHAPES_INCLUDE_SHAPE_H

#include "core/transform.h"
#include "core/tuple.h"
#include "intersection.h"
#include "light/ray.h"
#include "material.h"
#include <optional>

namespace ray_tracer {
namespace shapes {

class Intersection;

using Intersections = std::vector<Intersection>;

class Shape : public std::enable_shared_from_this<Shape> {
 protected:
  Shape() = default;
  Shape(Transform transformation) { set_transform(transformation); };
  Shape(Transform transformation, std::shared_ptr<Material> material)
      : material{material} {
    set_transform(transformation);
  };
  Transform transformation_inverse{Identity()};
  std::shared_ptr<Material> material{Material::create()};

 public:
  virtual std::optional<const Intersections> intersect(
      const Ray& ray) const = 0;
  virtual Vector normal_at(const Point& point) const = 0;

  // To do: streamline this
  Color lighting(const Light& light, const Point& reflection_point,
                 const Vector& eye_vector, const Vector& normal_vector) const {
    return material->lighting(light, reflection_point, eye_vector,
                              normal_vector);
  };

  void set_transform(Transform transformation) {
    transformation_inverse = transformation.Inv();
  }
  void set_material(std::shared_ptr<Material> new_material) {
    material = new_material;
  }
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
