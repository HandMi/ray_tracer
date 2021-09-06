#include "core/canvas.h"
#include "writer/ppm_writer.h"
#include "projectile.h"
#include <fstream>
#include <iostream>

void tick(const Environment& environment, Projectile& projectile) {
  projectile.position += projectile.velocity;
  projectile.velocity += environment.gravity + environment.wind;
}

int main() {
  constexpr int width = 768;
  constexpr int height = 512;
  ray_tracer::Canvas canvas{width, height};

  ray_tracer::Vector v{1.0, 2.0, 0.};
  v.normalize();
  Projectile p{{0., 0.1, 0.}, v};
  Environment env{{0., -0.01, 0.}, {-0.001, 0., 0.}};
  while (p.position.y() > 0.) {
    tick(env, p);
    canvas.set(p.position.x() * 10., height - p.position.y() * 10.,
               {1., 0., 0.});
    std::cout << "Projectile position: " << p.position.x() << " " << p.position.y()
              << " " << p.position.z() << std::endl;
  }

  ray_tracer::writer::PPMWriter writer{};
  std::ofstream file_stream;
  file_stream.open("projectile.ppm");
  writer.printCanvas(canvas, file_stream);
  file_stream.close();
  return 0;
}
