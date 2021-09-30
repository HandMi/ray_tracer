#ifndef CORE_INCLUDE_COLOR_H
#define CORE_INCLUDE_COLOR_H

#include "tuple.h"
#include "common/types.h"

namespace ray_tracer {
struct Color : Tuple<3U, Color> {
  Color() = default;
  constexpr Color(Decimal r, Decimal g, Decimal b) : Tuple{{r, g, b}} {};

  constexpr Decimal r() const { return data[0]; };
  constexpr Decimal g() const { return data[1]; };
  constexpr Decimal b() const { return data[2]; };
  constexpr Decimal& r() { return data[0]; };
  constexpr Decimal& g() { return data[1]; };
  constexpr Decimal& b() { return data[2]; };

  constexpr Color& operator+=(const Color& a) {
    r() += a.r();
    g() += a.g();
    b() += a.b();
    return *this;
  }

  constexpr Color& operator-=(const Color& a) {
    r() -= a.r();
    g() -= a.g();
    b() -= a.b();
    return *this;
  }

  constexpr Color operator+(const Color& a) const {
    return {r() + a.r(), g() + a.g(), b() + a.b()};
  }

  constexpr Color operator-(const Color& a) const {
    return {r() - a.r(), g() - a.g(), b() - a.b()};
  }
};

// Hadamard multiplication
constexpr Color operator*(const Color& a, const Color& b) {
  return {a.r() * b.r(), a.g() * b.g(), a.b() * b.b()};
}

namespace Colors {
constexpr Color Black{0., 0., 0.};
}
}  // namespace ray_tracer

#endif
