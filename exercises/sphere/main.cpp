#include "core/canvas.h"
#include "light/ray.h"
#include "shapes/intersection.h"
#include "shapes/material.h"
#include "shapes/sphere.h"
#include "utils/types.h"
#include "writer/ppm_writer.h"
#include <fstream>
#include <iostream>

int main() {
  using namespace ray_tracer;

  constexpr int canvas_size = 2048;
  Canvas canvas{canvas_size, canvas_size};

  const auto sphere{shapes::Sphere::create(
      Identity(), shapes::Material::create(Color{0.8, 0.1, 0.1}))};
  const Point ray_origin{0., 0., -5.};
  const Decimal wall_distance = 10.;
  const Decimal wall_size = 7.;
  const Decimal pixel_size = wall_size / canvas_size;

  const Point light_position{-10., 10., -10.};
  const Color light_color{1., 1., 1.};
  const PointLight light{light_position, light_color};
  for (int i = 0; i < canvas_size; ++i) {
    for (int j = 0; j < canvas_size; ++j) {
      Decimal x = pixel_size * i - wall_size / 2.;
      Decimal y = wall_size / 2. - pixel_size * j;
      Vector direction{x, y, 15.};
      direction.normalize();
      const Ray ray{ray_origin, direction};
      const auto intersections = sphere->intersect(ray);
      shapes::IntersectionList intersection_list;
      intersection_list.append(intersections);
      const auto hit = intersection_list.hit_candidate();
      if (hit.has_value()) {
        const auto point = ray.position(hit->t);
        const auto normal = hit->object->normal_at(point);
        const auto eye_vector = -ray.direction;
        const auto color =
            hit->object->lighting(light, point, eye_vector, normal);
        canvas.set(i, j, color);
      }
    }
  }

  writer::PPMWriter writer{};
  std::ofstream file_stream;
  file_stream.open("sphere.ppm");
  writer.printCanvas(canvas, file_stream);
  file_stream.close();
  return 0;
}
