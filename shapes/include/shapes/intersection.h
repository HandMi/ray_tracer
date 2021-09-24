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

struct Intersection {
  Decimal t;
  std::shared_ptr<const Shape> object;
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

  std::optional<Intersection> hit_candidate();
};

struct Hit {
  std::shared_ptr<const Shape> object;
  bool inside{};
  Point point{};
  Vector eye_vector{};
  Vector normal{};
};

Hit prepare_hit(const Intersection& intersection, const Ray& ray);

}  // namespace shapes
}  // namespace ray_tracer

#endif
