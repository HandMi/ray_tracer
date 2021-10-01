#ifndef MATH_INCLUDE_MATRIX_H
#define MATH_INCLUDE_MATRIX_H

#include "common/types.h"
#include <array>

namespace ray_tracer {
namespace math {

template <template <UInteger, UInteger> class Derived, UInteger rows,
          UInteger cols>
class MatrixBase {
 public:
  MatrixBase(){};
  constexpr MatrixBase(
      const std::array<std::array<Decimal, cols>, rows> matrix) {
    for (UInteger i = 0U; i < rows; ++i) {
      for (UInteger j = 0U; j < cols; ++j) {
        data[i * cols + j] = matrix[i][j];
      }
    }
  }
  static constexpr UInteger get_rows() { return rows; }
  static constexpr UInteger get_cols() { return cols; }

  constexpr Decimal& operator()(UInteger i, UInteger j) {
    return data[i * cols + j];
  }

  constexpr Decimal operator()(UInteger i, UInteger j) const {
    return data[i * cols + j];
  }

  constexpr Derived<cols, rows> T() const {
    Derived<cols, rows> transpose{};
    for (UInteger i = 0U; i < rows; ++i) {
      for (UInteger j = 0U; j < cols; ++j) {
        transpose(j, i) = (*this)(i, j);
      }
    }
    return transpose;
  }

  template <UInteger r = rows, UInteger c = cols>
  constexpr typename std::enable_if<r == c, Derived<c, r>&>::type T() {
    for (UInteger i = 0U; i < r; ++i) {
      for (UInteger j = i + 1; j < c; ++j) {
        std::swap((*this)(i, j), (*this)(j, i));
      }
    }
    return static_cast<Derived<c, r>&>(*this);
  }

  template <UInteger r = rows, UInteger c = cols>
  constexpr
      typename std::enable_if<(r > 1) && (c > 1), Derived<c - 1, r - 1>>::type
      sub(UInteger row, UInteger col) const {
    Derived<r - 1, c - 1> sub_matrix{};
    for (UInteger i = 0U; i < r - 1; ++i) {
      const auto k = i < row ? i : i + 1;
      for (UInteger j = 0U; j < c - 1; ++j) {
        const auto m = j < col ? j : j + 1;
        sub_matrix(i, j) = (*this)(k, m);
      }
    }
    return sub_matrix;
  }

  template <UInteger r = rows, UInteger c = cols>
  constexpr
      typename std::enable_if<(r == c) && (r == 2) && (c == 2), Decimal>::type
      determinant() const {
    return (*this)(0, 0) * (*this)(1, 1) - (*this)(1, 0) * (*this)(0, 1);
  }

  // This should probably replaced by LU factorization
  template <UInteger r = rows, UInteger c = cols>
  constexpr
      typename std::enable_if<(r == c) && (r > 2) && (c > 2), Decimal>::type
      determinant() const {
    Decimal det{0.};
    for (UInteger i = 0; i < c; ++i) {
      det += (*this)(0, i) * cofactor(0, i);
    }
    return det;
  }

  template <UInteger r = rows, UInteger c = cols>
  constexpr typename std::enable_if<r == c, Decimal>::type minorant(
      UInteger row, UInteger col) const {
    return sub(row, col).determinant();
  }

  template <UInteger r = rows, UInteger c = cols>
  constexpr typename std::enable_if<r == c, Decimal>::type cofactor(
      UInteger row, UInteger col) const {
    return (row + col) % 2 == 1 ? -1. * minorant(row, col) : minorant(row, col);
  }

  template <UInteger r = rows, UInteger c = cols>
  constexpr typename std::enable_if<(r == c), Derived<r, c>>::type Inv() const {
    constexpr Decimal EPSILON = 1e-07;
    auto det = determinant();
    if (std::abs(det) < EPSILON) {
      throw std::domain_error("Matrix not invertible");
    }
    Derived<r, c> inverse{};
    for (UInteger i = 0U; i < r; ++i) {
      for (UInteger j = 0U; j < c; ++j) {
        inverse(i, j) = cofactor(i, j) / det;
      }
    }
    return inverse.T();
  }

  template <UInteger cols2>
  constexpr friend Derived<rows, cols2> operator*(
      const Derived<rows, cols>& matrix1, const Derived<cols, cols2>& matrix2) {
    Derived<rows, cols2> matrix_product{};
    for (UInteger i = 0U; i < rows; ++i) {
      for (UInteger j = 0U; j < cols2; ++j) {
        for (UInteger k = 0U; k < cols; ++k) {
          matrix_product(i, j) += matrix1(i, k) * matrix2(k, j);
        }
      }
    }
    return matrix_product;
  }

 private:
  std::array<Decimal, rows * cols> data{};
};

template <UInteger rows, UInteger cols>
struct Matrix : public MatrixBase<Matrix, rows, cols> {
  Matrix(){};
  constexpr Matrix(const std::array<std::array<Decimal, cols>, rows> matrix)
      : MatrixBase<Matrix, rows, cols>(matrix) {}
};

using Matrix4 = Matrix<4U, 4U>;

template <template <UInteger, UInteger> class Derived, UInteger rows>
constexpr Derived<rows, rows> Identity() {
  Derived<rows, rows> identity{};
  for (UInteger i = 0U; i < rows; ++i) {
    identity(i, i) = 1.;
  }
  return identity;
}
constexpr Matrix4 Identity4() { return Identity<Matrix, 4U>(); }

}  // namespace math
}  // namespace ray_tracer

#endif
