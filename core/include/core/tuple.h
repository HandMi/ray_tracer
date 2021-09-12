#ifndef CORE_INCLUDE_TUPLE_H
#define CORE_INCLUDE_TUPLE_H

#include "math/matrix.h"
#include "transformations.h"
#include "utils/types.h"
#include <array>
#include <cmath>

namespace ray_tracer {
template <UInteger size>
struct Tuple {
  Tuple() = default;
  constexpr Tuple(std::array<Decimal, size> data) : data(data){};
  constexpr Decimal& operator()(UInteger i) { return data[i]; };
  constexpr Decimal operator()(UInteger i) const { return data[i]; };

  constexpr Tuple& operator*=(const Decimal& a) {
    for (auto& x : data) {
      x *= a;
    }
    return *this;
  }

  constexpr Tuple& operator/=(const Decimal& a) {
    for (auto& x : data) {
      x /= a;
    }
    return *this;
  }
  // Scalar multiplication
  constexpr friend Tuple operator*(const Decimal& a, const Tuple& b) {
    Tuple result{b};
    result *= a;
    return result;
  }

  constexpr friend Tuple operator*(const Tuple& a, const Decimal& b) {
    return b * a;
  }

  // Scalar division
  constexpr friend Tuple operator/(const Tuple& a, const Decimal& b) {
    Tuple result{a};
    result /= b;
    return result;
  }

 protected:
  std::array<Decimal, size> data{};
};

struct Vector : public Tuple<4U>, Transformations<Vector> {
  Vector() = default;
  constexpr Vector(Decimal x, Decimal y, Decimal z) : Tuple({x, y, z, 0.}){};
  constexpr Vector(const Tuple& a) : Tuple(a){};
  constexpr Decimal x() const { return data[0]; };
  constexpr Decimal y() const { return data[1]; };
  constexpr Decimal z() const { return data[2]; };

  constexpr Vector& operator*=(const Decimal& a) {
    Tuple::operator*=(a);
    return *this;
  }

  constexpr Vector& operator/=(const Decimal& a) {
    Tuple::operator/=(a);
    return *this;
  }

  // Scalar multiplication
  constexpr friend Vector operator*(const Decimal& a, const Vector& b) {
    Vector result{b};
    result *= a;
    return result;
  }

  constexpr friend Vector operator*(const Vector& a, const Decimal& b) {
    return b * a;
  }

  // Scalar division
  constexpr friend Vector operator/(const Vector& a, const Decimal& b) {
    Vector result{a};
    result /= b;
    return result;
  }

  // Vector Addition

  constexpr Vector operator-() const { return Vector(-x(), -y(), -z()); }

  constexpr Vector operator+(const Vector& a) const {
    return {x() + a.x(), y() + a.y(), z() + a.z()};
  }

  constexpr Vector operator-(const Vector& a) const {
    return {x() - a.x(), y() - a.y(), z() - a.z()};
  }

  constexpr Vector& operator+=(const Vector& a) {
    data[0] += a.x();
    data[1] += a.y();
    data[2] += a.z();
    return *this;
  }

  constexpr Vector& operator-=(const Vector& a) {
    data[0] -= a.x();
    data[1] -= a.y();
    data[2] -= a.z();
    return *this;
  }

  constexpr Decimal length() const {
    return std::sqrt(x() * x() + y() * y() + z() * z());
  }
  constexpr void normalize() { *this /= length(); }
};

struct Point : Tuple<4U>, Transformations<Point> {
  Point() = default;
  constexpr Point(Decimal x, Decimal y, Decimal z) : Tuple({x, y, z, 1.0}){};
  constexpr Point(const Tuple& a) : Tuple(a){};
  constexpr Decimal x() const { return data[0]; };
  constexpr Decimal y() const { return data[1]; };
  constexpr Decimal z() const { return data[2]; };

  constexpr Point& operator+=(const Vector& a) {
    data[0] += a.x();
    data[1] += a.y();
    data[2] += a.z();
    return *this;
  }
};

// Addition
constexpr Point operator+(const Point& a, const Vector& b) {
  return {a.x() + b.x(), a.y() + b.y(), a.z() + b.z()};
}

// Subtraction
constexpr Point operator-(const Point& a, const Vector& b) {
  return {a.x() - b.x(), a.y() - b.y(), a.z() - b.z()};
}

constexpr Vector operator-(const Point& a, const Point& b) {
  return {a.x() - b.x(), a.y() - b.y(), a.z() - b.z()};
}

// Dot product

constexpr Decimal dot(const Vector& a, const Vector& b) {
  return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

// Cross product

constexpr Vector cross(const Vector& a, const Vector& b) {
  return {a.y() * b.z() - a.z() * b.y(), a.z() * b.x() - a.x() * b.z(),
          a.x() * b.y() - a.y() * b.x()};
}

}  // namespace ray_tracer

#endif