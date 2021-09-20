#ifndef SHAPES_INCLUDE_INTERSECTION_H
#define SHAPES_INCLUDE_INTERSECTION_H

#include "utils/types.h"
#include <algorithm>
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
  void append(const std::optional<const Intersections>& intersections) {
    if (intersections.has_value()) {
      data.insert(data.end(), intersections->begin(), intersections->end());
    }
  };
  void insert(const Intersection& intersection) {
    data.push_back(intersection);
  };
  void sort() {
    std::sort(
        data.begin(), data.end(),
        [](const Intersection& a, const Intersection& b) { return a.t < b.t; });
  }

  std::optional<Intersection> hit() {
    sort();
    const auto hiterator = std::lower_bound(
        data.begin(), data.end(), 0.,
        [](const Intersection& a, Decimal b) { return a.t < b; });
    return hiterator != data.end() ? std::optional<Intersection>(*hiterator)
                                   : std::nullopt;
  };
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
