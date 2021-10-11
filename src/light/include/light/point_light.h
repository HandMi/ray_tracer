#ifndef RAYS_INCLUDE_POINT_LIGHT_H
#define RAYS_INCLUDE_POINT_LIGHT_H

#include "core/color.h"
#include "light.h"
#include <memory>

namespace ray_tracer {

class PointLight : public Light {
 public:
  PointLight(const Point& point, const Color& color) : Light{point, color} {};
  Decimal intensity_at(const World& world, const Point& point) const override;
  Color lighting(const std::shared_ptr<const shapes::Material> material,
                 const Point& reflection_point, const Vector& eye_vector,
                 const Vector& normal_vector,
                 const Decimal intensity = 1.0) const override;
};

}  // namespace ray_tracer

#endif
