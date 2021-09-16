#ifndef RAYS_INCLUDE_RAY_H
#define RAYS_INCLUDE_RAY_H

#include "core/tuple.h"

namespace ray_tracer {

struct Ray {
  Point origin;
  Vector direction;
};

constexpr Ray operator*(const Transform& transform, const Ray& ray) {
  return {transform * ray.origin, transform * ray.direction};
};

constexpr Point position(const Ray& ray, Decimal distance) {
  return ray.origin + distance * ray.direction;
}

}  // namespace ray_tracer

#endif
