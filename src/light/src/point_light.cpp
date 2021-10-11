#include "light/point_light.h"
#include "world/world.h"

namespace ray_tracer {

Decimal PointLight::intensity_at(const World& world, const Point& point) const {
  if (world.is_shadowed(point, position)) {
    return 0.;
  }
  return 1.;
};

Color PointLight::lighting(const std::shared_ptr<const shapes::Material> material,
                      const Point& reflection_point, const Vector& eye_vector,
                      const Vector& normal_vector,
                      const Decimal intensity) const {
  Color diffuse_color{}, specular_color{}, ambient_color{};
  const auto effective_color = material->color * color;
  auto light_vector = (position - reflection_point);
  light_vector.normalize();
  ambient_color = effective_color * material->ambient;
  const auto light_dot_normal = dot(light_vector, normal_vector);
  if (light_dot_normal > 0.) {
    diffuse_color =
        intensity * effective_color * material->diffuse * light_dot_normal;
    const auto reflect_light_vector = reflect(-light_vector, normal_vector);
    const auto reflect_dot_eye = dot(reflect_light_vector, eye_vector);
    if (reflect_dot_eye > 0.) {
      const auto specular_factor =
          std::pow(reflect_dot_eye, material->shininess);
      specular_color = intensity * material->specular * specular_factor * color;
    }
  }
  return ambient_color + diffuse_color + specular_color;
}
}  // namespace ray_tracer
