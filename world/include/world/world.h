#ifndef WORLD_INCLUDE_WORLD_H
#define WORLD_INCLUDE_WORLD_H

#include "light/point_light.h"
#include "shapes/intersection.h"
#include "shapes/shape.h"
#include <memory>
#include <vector>

namespace ray_tracer {

class World {
 private:
  std::vector<PointLight> lights{};
  std::vector<std::shared_ptr<shapes::Shape>> shapes;

 public:
  static World Default();
  World() = default;
  World(const std::vector<PointLight>& lights,
        const std::vector<std::shared_ptr<shapes::Shape>>& shapes)
      : lights{lights}, shapes{shapes} {};

  shapes::IntersectionList intersect(const Ray& ray) const;
  Color shade(const shapes::Hit& hit) const;
  Color color_at(const Ray& ray) const;
  bool is_shadowed(const Point& point, const PointLight& light) const;
};

}  // namespace ray_tracer

#endif
