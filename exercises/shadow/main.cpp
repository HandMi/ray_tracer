#include "core/canvas.h"
#include "light/ray.h"
#include "shapes/sphere.h"
#include "common/types.h"
#include "writer/ppm_writer.h"
#include <fstream>
#include <iostream>

int main() {
  constexpr int canvas_size = 1024;
  ray_tracer::Canvas canvas{canvas_size, canvas_size};

  const auto sphere{ray_tracer::shapes::Sphere::create()};
  const ray_tracer::Point ray_origin{0., 0., -5.};
  const ray_tracer::Decimal wall_distance = 10.;
  const ray_tracer::Decimal wall_size = 7.;
  const ray_tracer::Decimal pixel_size = wall_size / canvas_size;
  for (int i = 0; i < canvas_size; ++i) {
    for (int j = 0; j < canvas_size; ++j) {
      ray_tracer::Decimal x = pixel_size * i - wall_size / 2.;
      ray_tracer::Decimal y = wall_size / 2. - pixel_size * j;
      ray_tracer::Vector direction{x, y, 15.};
      direction.normalize();
      const ray_tracer::Ray ray{ray_origin, direction};
      const auto intersections = sphere->intersect(ray);
      if (intersections.has_value()) {
        canvas.set(i, j, {1., 0., 0.});
      }
    }
  }

  ray_tracer::writer::PPMWriter writer{};
  std::ofstream file_stream;
  file_stream.open("shadow.ppm");
  writer.printCanvas(canvas, file_stream);
  file_stream.close();
  return 0;
}
