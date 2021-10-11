#include "camera/camera.h"
#include "common/types.h"
#include "core/tuple.h"

namespace ray_tracer {

Camera::Camera(UInteger hsize, UInteger vsize, Decimal fov)
    : hsize(hsize), vsize(vsize), fov(fov) {
  const Decimal half_view = std::tan(fov / 2.);
  const Decimal aspect_ratio = static_cast<Decimal>(hsize) / vsize;
  half_width = aspect_ratio >= 1. ? half_view : half_view * aspect_ratio;
  half_height = aspect_ratio >= 1. ? half_view / aspect_ratio : half_view;
  pixel_size = 2. * half_width / hsize;
};

Ray Camera::ray_to_pixel(UInteger x, UInteger y) const {
  const auto x_offset = (x + 0.5) * pixel_size;
  const auto y_offset = (y + 0.5) * pixel_size;

  const auto x_world = half_width - x_offset;
  const auto y_world = half_height - y_offset;

  const auto pixel = transform_inv * Point(x_world, y_world, -1.);
  const auto origin = transform_inv * Point(0., 0., 0.);
  auto direction = pixel - origin;
  direction.normalize();
  return Ray{origin, direction};
};

Canvas Camera::render(const World& world) const {
  Canvas image(hsize, vsize);
  for (UInteger y = 0U; y < vsize; ++y) {
    for (UInteger x = 0U; x < hsize; ++x) {
      const auto ray = ray_to_pixel(x, y);
      const auto color = world.color_at(ray);
      image.set(x, y, color);
    }
  }
  return image;
};
}  // namespace ray_tracer
