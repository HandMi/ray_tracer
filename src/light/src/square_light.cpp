#include "light/square_light.h"
#include "common/types.h"
#include "world/world.h"

namespace ray_tracer {

// Todo: wrap the rng
std::mt19937 rng(1337U);

Point SquareLight::point_on_light(UInteger u, UInteger v) const {
  std::uniform_real_distribution<Decimal> dis(0., 1.);

  return position + (u + dis(rng)) * u_vector + (v + dis(rng)) * v_vector;
}

Decimal SquareLight::intensity_at(const World& world,
                                  const Point& point) const {
  Decimal total{};
  for (UInteger v = 0; v < v_steps; ++v) {
    for (UInteger u = 0; u < u_steps; ++u) {
      const auto light_position = point_on_light(u, v);
      if (!world.is_shadowed(point, light_position)) {
        total += 1.;
      }
    }
  }
  return total / static_cast<Decimal>(samples);
}

Color SquareLight::lighting(
    const std::shared_ptr<const shapes::Material> material,
    const Point& reflection_point, const Vector& eye_vector,
    const Vector& normal_vector, const Decimal intensity) const {
  Color diffuse_sum{}, specular_sum{}, ambient_color{};
  const auto effective_color = material->color * color;
  ambient_color = effective_color * material->ambient;
  for (UInteger v = 0; v < v_steps; ++v) {
    for (UInteger u = 0; u < u_steps; ++u) {
      const auto light_position = point_on_light(u, v);
      auto light_vector = (light_position - reflection_point);
      light_vector.normalize();
      const auto light_dot_normal = dot(light_vector, normal_vector);
      if (light_dot_normal > 0.) {
        diffuse_sum += effective_color * material->diffuse * light_dot_normal;
        const auto reflect_light_vector = reflect(-light_vector, normal_vector);
        const auto reflect_dot_eye = dot(reflect_light_vector, eye_vector);
        if (reflect_dot_eye > 0.) {
          const auto specular_factor =
              std::pow(reflect_dot_eye, material->shininess);
          specular_sum += material->specular * specular_factor * color;
        }
      }
    }
  }
  return ambient_color + intensity / static_cast<Decimal>(samples) *
                             (diffuse_sum + specular_sum);
}
}  // namespace ray_tracer
