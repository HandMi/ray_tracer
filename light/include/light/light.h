#ifndef RAYS_INCLUDE_LIGHT_H
#define RAYS_INCLUDE_LIGHT_H

#include "core/tuple.h"
#include "core/color.h"


namespace ray_tracer {

struct Light {
  Point position;
  Color intensity;
};

}  // namespace ray_tracer

#endif
