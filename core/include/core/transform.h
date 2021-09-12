#ifndef CORE_INCLUDE_TRANSFORM_H
#define CORE_INCLUDE_TRANSFORM_H

#include "math/matrix.h"
#include "transformations.h"
#include <array>
#include <cmath>

namespace ray_tracer {
template <UInteger rows = 4U, UInteger cols = 4U>
struct TransformBase
    : public math::MatrixBase<TransformBase, rows, cols>,
      Transformations<TransformBase<rows, cols>, TransformBase<rows, cols>> {
  TransformBase(){};
  constexpr TransformBase(
      const std::array<std::array<Decimal, cols>, rows> matrix)
      : math::MatrixBase<TransformBase, rows, cols>(matrix){};
};

template <UInteger rows = 4U, UInteger cols = 4U>
constexpr TransformBase<rows, cols> Identity() {
  return math::Identity<TransformBase, 4U>();
}

using Transform = TransformBase<>;
}  // namespace ray_tracer
#endif
