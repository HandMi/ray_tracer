#ifndef SHAPES_INCLUDE_I_SHAPE_H
#define SHAPES_INCLUDE_I_SHAPE_H

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

class IShape : public std::enable_shared_from_this<IShape> {
 protected:
  IShape() = default;
  IShape(Transform transformation, std::shared_ptr<Material> material)
      : transformation_inverse{transformation.Inv()}, material{material} {};
  IShape(Transform transformation)
      : IShape(transformation, Material::create()){};
  const Transform transformation_inverse{Identity()};
  std::shared_ptr<const Material> material{Material::create()};

 public:
  virtual std::optional<const Intersections> intersect(
      const Ray& ray) const = 0;
  virtual Vector normal_at(const Point& point) const = 0;

  std::shared_ptr<const Material> get_material() const { return material; }
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
