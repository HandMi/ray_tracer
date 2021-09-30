
#ifndef UTILS_INCLUDE_MATRIX_TEST_HELPER_H
#define UTILS_INCLUDE_MATRIX_TEST_HELPER_H

#include "math/matrix.h"
#include <cmath>
#include <iostream>

namespace ray_tracer {

template <class MatrixType>
bool ApproxEqual(const MatrixType& matrix1, const MatrixType& matrix2,
                 const Decimal epsilon = 0.0001) {
  for (UInteger i = 0; i < MatrixType::get_rows(); ++i) {
    for (UInteger j = 0; j < MatrixType::get_cols(); ++j) {
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
