#ifndef CORE_INCLUDE_COLOR_H
#define CORE_INCLUDE_COLOR_H

#include "types.h"

namespace ray_tracer {
struct Color {
  Color() = default;
  constexpr Color(Decimal r, Decimal g, Decimal b) : r{r}, g{g}, b{b} {};

  Decimal r;
  Decimal g;
  Decimal b;

  constexpr Color& operator*=(const Decimal& a) {
    r *= a;
    g *= a;
    b *= a;
    return *this;
  }

  constexpr Color& operator/=(const Decimal& a) {
    r /= a;
    g /= a;
    b /= a;
    return *this;
  }

  constexpr Color& operator+=(const Color& a) {
    r += a.r;
    g += a.g;
    b += a.b;
    return *this;
  }

  constexpr Color& operator-=(const Color& a) {
    r -= a.r;
    g -= a.g;
    b -= a.b;
    return *this;
  }


  constexpr Color operator+(const Color& a) const {
    return {r + a.r, g + a.g, b + a.b};
  }

  constexpr Color operator-(const Color& a) const {
    return {r - a.r, g - a.g, b - a.b};
  }
};

// Scalar multiplication
inline Color operator*(const Decimal& a, const Color& b) {
  return {a * b.r, a * b.g, a * b.b};
}

inline Color operator*(const Color& a, const Decimal& b) { return b * a; }

// Hadamard multiplication
inline Color operator*(const Color& a, const Color& b) {
  return {a.r * b.r, a.g * b.g, a.b * b.b};
}

}  // namespace ray_tracer

#endif