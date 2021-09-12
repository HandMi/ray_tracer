#ifndef CORE_INCLUDE_TRANSFORMATIONS_H
#define CORE_INCLUDE_TRANSFORMATIONS_H

#include "math/matrix.h"
#include <array>
#include <cmath>

namespace ray_tracer {
template <class T>
struct Transformations {
  constexpr T& translate(Decimal x, Decimal y, Decimal z) {
    auto ptr_to_derived = static_cast<T*>(this);
    math::Matrix4 translation_matrix{{{{1., 0., 0., x},
                                       {0., 1., 0., y},
                                       {0., 0., 1., z},
                                       {0., 0., 0., 1.}}}};
    *ptr_to_derived = translation_matrix * (*this);
    return static_cast<T&>(*ptr_to_derived);
  }
  constexpr T& scale(Decimal x, Decimal y, Decimal z) {
    auto ptr_to_derived = static_cast<T*>(this);
    math::Matrix4 translation_matrix{{{{x, 0., 0., 0.},
                                       {0., y, 0., 0.},
                                       {0., 0., z, 0.},
                                       {0., 0., 0., 1.}}}};
    *ptr_to_derived = translation_matrix * (*this);
    return static_cast<T&>(*ptr_to_derived);
  }
};

template <class T>
constexpr T operator*(const math::Matrix4& matrix,
                      const Transformations<T>& tuple) {
  auto ref_to_derived = static_cast<const T&>(tuple);
  T product{};
  for (UInteger i = 0U; i < 4U; ++i) {
    for (UInteger j = 0U; j < 4U; ++j) {
      product(i) += matrix(i, j) * ref_to_derived(j);
    }
  }
  return product;
}
}  // namespace ray_tracer
#endif