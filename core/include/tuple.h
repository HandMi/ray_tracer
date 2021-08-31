#ifndef CORE_INCLUDE_TUPLE_H
#define CORE_INCLUDE_TUPLE_H

#include "types.h"
#include <cmath>

namespace ray_tracer {
struct Tuple {
  Tuple() = default;
  constexpr Tuple(Decimal x, Decimal y, Decimal z) : x{x}, y{y}, z{z} {};

  Decimal x;
  Decimal y;
  Decimal z;

  constexpr Tuple& operator*=(const Decimal& a) {
    x *= a;
    y *= a;
    z *= a;
    return *this;
  }

  constexpr Tuple& operator/=(const Decimal& a) {
    x /= a;
    y /= a;
    z /= a;
    return *this;
  }
};

struct Vector : Tuple {
  Vector() = default;
  constexpr Vector(Decimal x, Decimal y, Decimal z) : Tuple(x, y, z){};

  constexpr Vector operator-() const { return Vector(-x, -y, -z); }

  constexpr Vector operator+(const Vector& a) const {
    return Vector(x + a.x, y + a.y, z + a.z);
  }

  constexpr Vector operator-(const Vector& a) const {
    return Vector(x - a.x, y - a.y, z - a.z);
  }

  constexpr Vector& operator+=(const Vector& a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
  }

  constexpr Vector& operator-=(const Vector& a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
  }

  constexpr Decimal length() const { return std::sqrt(x * x + y * y + z * z); }
  constexpr void normalize() { *this /= length(); }
};

struct Point : Tuple {
  Point() = default;
  constexpr Point(Decimal x, Decimal y, Decimal z) : Tuple(x, y, z){};

  constexpr Point& operator+=(const Vector& a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
  }
};

// Addition
inline Point operator+(const Point& a, const Vector& b) {
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}

// Subtraction
inline Point operator-(const Point& a, const Vector& b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

inline Vector operator-(const Point& a, const Point& b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

// Scalar multiplication
inline Tuple operator*(const Decimal& a, const Tuple& b) {
  return {a * b.x, a * b.y, a * b.z};
}

inline Tuple operator*(const Tuple& a, const Decimal& b) { return b * a; }

// Scalar division
inline Tuple operator/(const Tuple& a, const Decimal& b) {
  return {a.x / b, a.y / b, a.z / b};
}

// Dot product

constexpr Decimal dot(const Vector& a, const Vector& b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Cross product

constexpr Vector cross(const Vector& a, const Vector& b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

}  // namespace ray_tracer

#endif