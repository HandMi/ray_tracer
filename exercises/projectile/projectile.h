#ifndef EXERCISES_PROJECTILE_H
#define EXERCISES_PROJECTILE_H

#include "tuple.h"
struct Projectile {
  ray_tracer::Point position{};
  ray_tracer::Vector velocity{};
};

struct Environment {
  ray_tracer::Vector gravity{};
  ray_tracer::Vector wind{};
};
#endif