#ifndef RAYS_INCLUDE_RAY_H
#define RAYS_INCLUDE_RAY_H

#include "core/tuple.h"

namespace ray_tracer {

struct Ray {
  Point origin;
  Vector direction;
  Ray transform(const Transform& transform) const {
    return {transform * origin, transform * direction};
  };
};

constexpr Point position(const Ray& ray, Decimal distance) {
  return ray.origin + distance * ray.direction;
}

}  // namespace ray_tracer

#endif
