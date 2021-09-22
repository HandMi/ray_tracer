#ifndef SHAPES_INCLUDE_INTERSECTION_H
#define SHAPES_INCLUDE_INTERSECTION_H

#include "core/tuple.h"
#include "light/ray.h"
#include "utils/types.h"
#include <memory>
#include <optional>
#include <vector>

namespace ray_tracer {
namespace shapes {

class Shape;
struct Hit;

struct Intersection {
  Decimal t;
  std::shared_ptr<const Shape> object;
  Hit prepare_hit(const Ray& ray) const;
};

struct Hit : public Intersection {
  bool inside{};
  Point point{};
  Vector eye_vector{};
  Vector normal{};
};

using Intersections = std::vector<Intersection>;

class IntersectionList {
 private:
  Intersections data;

 public:
  IntersectionList() = default;
  IntersectionList(const std::initializer_list<Intersection>& data)
      : data(data){};
  Intersection operator[](UInteger i) const { return data[i]; };
  UInteger count() const { return data.size(); };
  void append(const std::optional<const Intersections>& intersections);
  void insert(const Intersection& intersection);
  void sort();

  std::optional<Intersection> hit();
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
