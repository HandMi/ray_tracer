#include "projectile.h"
#include <iostream>
void tick(const Environment& environment, Projectile& projectile) {
  projectile.position += projectile.velocity;
  projectile.velocity += environment.gravity + environment.wind;
}

int main() {
  ray_tracer::Vector v{1., 1., 0.};
  v.normalize();
  Projectile p{{0., 1., 0.}, v};
  Environment env{{0., -0.1, 0.}, {-0.01, 0., 0.}};
  while (p.position.y > 0.) {
    tick(env, p);
    std::cout << "Projectile position: " << p.position.x << " " << p.position.y
              << " " << p.position.z << std::endl;
  }
  return 0;
}
