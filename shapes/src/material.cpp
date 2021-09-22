#include "shapes/material.h"
#include "core/tuple.h"

namespace ray_tracer {
namespace shapes {

Color Material::lighting(const PointLight& light, const Point& reflection_point,
                         const Vector& eye_vector,
                         const Vector& normal_vector) {
  Color diffuse_color{}, specular_color{}, ambient_color{};
  const auto effective_color = color * light.intensity;
  auto light_vector = (light.position - reflection_point);
  light_vector.normalize();
  ambient_color = effective_color * ambient;
  const auto light_dot_normal = dot(light_vector, normal_vector);
  if (light_dot_normal > 0.) {
    diffuse_color = effective_color * diffuse * light_dot_normal;
    const auto reflect_light_vector = reflect(-light_vector, normal_vector);
    const auto reflect_dot_eye = dot(reflect_light_vector, eye_vector);
    if (reflect_dot_eye > 0.) {
      const auto specular_factor = std::pow(reflect_dot_eye, shininess);
      specular_color = light.intensity * specular * specular_factor;
    }
  }
  return ambient_color + diffuse_color + specular_color;
}
}  // namespace shapes
}  // namespace ray_tracer