#ifndef RAYS_INCLUDE_SQUARE_LIGHT_H
#define RAYS_INCLUDE_SQUARE_LIGHT_H

#include "common/types.h"
#include "core/color.h"
#include "i_light.h"
#include <memory>
#include <random>

namespace ray_tracer {

class SquareLight : public ILight {
 private:
  Point point_on_light(UInteger u, UInteger v) const;

 public:
  SquareLight(const Point& point, const Color& color, const Vector& u_vector,
              UInteger u_steps, const Vector& v_vector, UInteger v_steps)
      : ILight{point, color},
        u_vector{u_vector},
        u_steps{u_steps},
        v_vector{v_vector},
        v_steps{v_steps},
        samples{u_steps * v_steps} {};
  Decimal intensity_at(const World& world, const Point& point) const override;
  Color lighting(const std::shared_ptr<const shapes::Material> material,
                 const Point& reflection_point, const Vector& eye_vector,
                 const Vector& normal_vector,
                 const Decimal intensity = 1.0) const override;
  // Square light extends in these directions
  const Vector u_vector{};
  const UInteger u_steps{};
  const Vector v_vector{};
  const UInteger v_steps{};
  const UInteger samples{};
};

}  // namespace ray_tracer

#endif
