#ifndef CORE_INCLUDE_TUPLE_H
#define CORE_INCLUDE_TUPLE_H

#include "types.h"

namespace ray_tracer {
namespace core {
struct Tuple {
  Tuple() = default;
  Tuple(Decimal x, Decimal y, Decimal z) : x{x}, y{y}, z{z} {};

  Decimal x;
  Decimal y;
  Decimal z;
};

struct Vector : Tuple {
  Vector() = default;
  Vector(Decimal x, Decimal y, Decimal z) : Tuple(x, y, z){};

  Vector operator-() const { return Vector(-x, -y, -z); }

  Vector operator+(const Vector& a) const {
    return Vector(x + a.x, y + a.y, z + a.z);
  }

  Vector operator-(const Vector& a) const {
    return Vector(x - a.x, y - a.y, z - a.z);
  }

  Vector& operator+=(const Vector& a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
  }

  Vector& operator-=(const Vector& a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
  }
};

struct Point : Tuple {
  Point() = default;
  Point(Decimal x, Decimal y, Decimal z) : Tuple(x, y, z){};
};

inline Point operator+(const Point& a, const Vector& b) {
  return {a.x + b.x, a.y + b.y, a.z + b.z};
}

inline Point operator-(const Point& a, const Vector& b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

inline Vector operator-(const Point& a, const Point& b) {
  return {a.x - b.x, a.y - b.y, a.z - b.z};
}

}  // namespace core
}  // namespace ray_tracer

#endif