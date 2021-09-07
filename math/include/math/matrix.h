#ifndef MATH_INCLUDE_MATRIX_H
#define MATH_INCLUDE_MATRIX_H

#include "core/tuple.h"
#include "core/types.h"
#include <array>

namespace ray_tracer {
namespace math {

template <UInteger rows, UInteger cols>
class Matrix {
 public:
  Matrix(){};
  constexpr Matrix(const std::array<std::array<Decimal, cols>, rows> matrix) {
    for (UInteger i = 0U; i < rows; ++i) {
      for (UInteger j = 0U; j < cols; ++j) {
        data[i * cols + j] = matrix[i][j];
      }
    }
  }
  constexpr Decimal& operator()(UInteger i, UInteger j) {
    return data[i * cols + j];
  };
  constexpr Decimal operator()(UInteger i, UInteger j) const {
    return data[i * cols + j];
  };

  constexpr Matrix<cols, rows> T() const  {
    Matrix<cols, rows> transpose{};
    for (UInteger i = 0U; i < rows; ++i) {
      for (UInteger j = 0U; j < cols; ++j) {
        transpose(j, i) = (*this)(i, j);
      }
    }
    return transpose;
  }

  template <UInteger r = rows, UInteger c = cols,
            typename = typename std::enable_if<r == c>>
  constexpr Matrix<c, r>& T() {
    for (UInteger i = 0U; i < r; ++i) {
      for (UInteger j = i + 1; j < c; ++j) {
        std::swap((*this)(i, j), (*this)(j, i));
      }
    }
    return *this;
  }

 private:
  std::array<Decimal, rows * cols> data{};
};

using Matrix4 = Matrix<4U, 4U>;

template <UInteger rows>
constexpr Matrix<rows, rows> Identity() {
  Matrix<rows, rows> identity{};
  for (UInteger i = 0U; i < rows; ++i) {
    identity(i, i) = 1.;
  }
  return identity;
}

constexpr Matrix4 Identity4() { return Identity<4U>(); }

template <UInteger rows1, UInteger cols1, UInteger cols2>
constexpr Matrix<rows1, cols2> operator*(const Matrix<rows1, cols1>& matrix1,
                                         const Matrix<cols1, cols2>& matrix2) {
  Matrix<rows1, cols2> matrix_product{};
  for (UInteger i = 0U; i < rows1; ++i) {
    for (UInteger j = 0U; j < cols2; ++j) {
      for (UInteger k = 0U; k < cols1; ++k) {
        matrix_product(i, j) += matrix1(i, k) * matrix2(k, j);
      }
    }
  }
  return matrix_product;
}

template <UInteger rows, UInteger cols>
constexpr Tuple<rows> operator*(const Matrix<rows, cols>& matrix,
                                const Tuple<cols>& tuple) {
  Tuple<rows> product{};
  for (UInteger i = 0U; i < rows; ++i) {
    for (UInteger j = 0U; j < cols; ++j) {
      product(i) += matrix(i, j) * tuple(j);
    }
  }
  return product;
}

constexpr Vector operator*(const Matrix4& matrix, const Vector& vector) {
  return matrix * static_cast<const Tuple<4U>&>(vector);
}

constexpr Point operator*(const Matrix4& matrix, const Point& vector) {
  return matrix * static_cast<const Tuple<4U>&>(vector);
}

}  // namespace math
}  // namespace ray_tracer

#endif
