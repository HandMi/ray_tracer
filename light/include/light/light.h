#ifndef RAYS_INCLUDE_RAY_H
#define RAYS_INCLUDE_RAY_H

#include "core/tuple.h"
#include "core/color.h"


namespace ray_tracer {

struct Light {
  Color intensity;
  Point position;
};

}  // namespace ray_tracer

#endif
