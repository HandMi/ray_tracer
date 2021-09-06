#ifndef MATH_INCLUDE_MATRIX_H
#define MATH_INCLUDE_MATRIX_H

#include "core/types.h"
#include <array>

namespace ray_tracer {
namespace math {

template <UInteger rows, UInteger cols>
class Matrix {
 public:
  Matrix(){};
  Matrix(const std::array<std::array<Decimal, cols>, rows> matrix){
      for(UInteger i=0U;i<rows;++i){
          for(UInteger j=0U;j<cols;++j){
              data[i * cols + j] = data[i][j];
          }
      }
  }
  Decimal& operator()(UInteger i, UInteger j) { return data[i][j]; };
  Decimal operator()(UInteger i, UInteger j) const {
    return data[i * cols + j];
  };

 private:
  std::array<Decimal, rows * cols> data{};
};

}  // namespace math
}  // namespace ray_tracer

#endif