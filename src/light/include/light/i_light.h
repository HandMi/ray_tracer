#ifndef RAYS_INCLUDE_I_LIGHT_H
#define RAYS_INCLUDE_I_LIGHT_H

#include "core/color.h"
#include "core/tuple.h"
#include "shapes/material.h"
#include <memory>

namespace ray_tracer {

class World;

class ILight {
 protected:
  ILight() = default;
  ILight(const Point& point, const Color& color)
      : position{point}, color{color} {};

 public:
  const Point position{};
  const Color color{};
  virtual Decimal intensity_at(const World& world,
                               const Point& point) const = 0;
  virtual Color lighting(const std::shared_ptr<const shapes::Material> material,
                 const Point& reflection_point, const Vector& eye_vector,
                 const Vector& normal_vector, const Decimal intensity = 1.0) const = 0;
};

}  // namespace ray_tracer

#endif
