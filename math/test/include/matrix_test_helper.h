
#ifndef MATH_TEST_INCLUDE_MATRIX_TEST_HELPER_H
#define MATH_TEST_INCLUDE_MATRIX_TEST_HELPER_H

#include "math/matrix.h"
#include <cmath>
#include <iostream>

namespace ray_tracer {

template <UInteger rows, UInteger cols>
bool ApproxEqual(const math::Matrix<rows, cols>& matrix1,
                 const math::Matrix<rows, cols>& matrix2,
                 const Decimal epsilon = 0.0001) {
  for (UInteger i = 0; i < rows; ++i) {
    for (UInteger j = 0; j < cols; ++j) {
      if (std::abs(matrix1(i, j) - matrix2(i, j)) > epsilon) {
        std::cout << "Mismatch in row " << i << " col " << j << "\n";
        return false;
      }
    }
  }
  return true;
}

}  // namespace ray_tracer

#endif
