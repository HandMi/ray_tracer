#ifndef CORE_INCLUDE_VIEW_TRANSFORM_H
#define CORE_INCLUDE_VIEW_TRANSFORM_H

#include "transform.h"
#include "tuple.h"

namespace ray_tracer {

constexpr Transform view_transform(const Point& from, const Point& to,
                                   Vector up) {
  auto forward = to - from;
  forward.normalize();
  up.normalize();
  const auto left = cross(forward, up);
  const auto true_up = cross(left, forward);
  return Transform{{{{left.x(), left.y(), left.z(), 0.},
                     {true_up.x(), true_up.y(), true_up.z(), 0.},
                     {-forward.x(), -forward.y(), -forward.z(), 0.},
                     {0., 0., 0., 1.}}}} *
         Identity().translate(-from.x(), -from.y(), -from.z());
}
}  // namespace ray_tracer
#endif
