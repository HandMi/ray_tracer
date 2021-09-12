#include "core/canvas.h"
#include "core/tuple.h"
#include "writer/ppm_writer.h"
#include <fstream>
#include <iostream>

int main() {
  constexpr int width = 128;
  constexpr int height = 128;
  ray_tracer::Canvas canvas{width, height};

  for (int i = 0; i < 12; ++i) {
    ray_tracer::Point middle{width / 2., height / 2., 0};
    ray_tracer::Vector pointer{32., 0., 0.};
    pointer.rotate_z(ray_tracer::PI * i / 6.);
    auto result = middle + pointer;
    canvas.set(result.x(), result.y(), {1., 0., 0.});
  }

  ray_tracer::writer::PPMWriter writer{};
  std::ofstream file_stream;
  file_stream.open("clock.ppm");
  writer.printCanvas(canvas, file_stream);
  file_stream.close();
  return 0;
}
