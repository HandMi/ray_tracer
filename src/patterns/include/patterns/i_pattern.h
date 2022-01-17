#ifndef SHAPES_INCLUDE_I_PATTERN_H
#define SHAPES_INCLUDE_I_PATTERN_H

#include "core/transform.h"
#include "shapes/i_shape.h"

namespace ray_tracer {
namespace patterns {

class IPattern : public std::enable_shared_from_this<IPattern> {
  const Transform transform{};

 protected:
  IPattern() = default;
  IPattern(const Transform& transform) : transform{transform} {};

 public:
  virtual Color at(const Point& point) const = 0;
};
}  // namespace patterns
}  // namespace ray_tracer

#endif
