#ifndef CAMERA_INCLUDE_CAMERA_H
#define CAMERA_INCLUDE_CAMERA_H

#include "common/types.h"
#include "core/canvas.h"
#include "core/transform.h"
#include "light/ray.h"
#include "world/world.h"
#include <cmath>

namespace ray_tracer {

class Camera {
  const UInteger hsize{};
  const UInteger vsize{};
  const Decimal fov{};
  // should be const ..
  Decimal half_width{};
  Decimal half_height{};
  Decimal pixel_size{};
  Transform transform{Identity()};
  Transform transform_inv{Identity()};

 public:
  Camera() = default;
  Camera(UInteger hsize, UInteger vsize, Decimal fov);
  constexpr void set_transform(Transform transform_matrix) {
    transform = transform_matrix;
    transform_inv = transform_matrix.Inv();
  }
  constexpr Decimal get_pixel_size() const { return pixel_size; };
  Ray ray_to_pixel(UInteger x, UInteger y) const;
  Canvas render(const World& world) const;
};

}  // namespace ray_tracer

#endif
