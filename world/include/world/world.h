#ifndef WORLD_INCLUDE_WORLD_H
#define WORLD_INCLUDE_WORLD_H

#include "light/light.h"
#include "shapes/shape.h"
#include "shapes/intersection.h"
#include <memory>
#include <vector>

namespace ray_tracer {
namespace world {

class World {
 private:
  Light light{};
  std::vector<std::shared_ptr<shapes::Shape>> shapes;

 public:
  World() = default;
  World(const Light& light, const std::vector < std::shared_ptr<shapes::Shape>> & shapes)
      : light{light}, shapes{shapes}{};
  static World Default();
  shapes::IntersectionList intersect(const Ray& ray) const;
};

}  // namespace world
}  // namespace ray_tracer

#endif
