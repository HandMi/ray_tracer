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
  using LightList = std::vector<std::unique_ptr<const Light>>;
  using ShapeList = std::vector<std::shared_ptr<const shapes::Shape>>;
  LightList lights{};
  ShapeList shapes{};

 public:
  static World Default();
  World() = default;
  World(LightList lights, const ShapeList& shapes)
      : lights(std::move(lights)), shapes{shapes} {};

  template <typename LightType, typename... T>
  void addLight(T&&... args) {
    lights.push_back(
        std::make_unique<const LightType>(std::forward<T>(args)...));
  }

  template <typename ShapeType, typename... T>
  void addShape(T&&... args) {
    shapes.push_back(ShapeType::create(std::forward<T>(args)...));
  }

  shapes::IntersectionList intersect(const Ray& ray) const;
  Color shade(const shapes::Hit& hit) const;
  Color color_at(const Ray& ray) const;
  bool is_shadowed(const Point& point, const Point& light_position) const;
};
};  // namespace ray_tracer

#endif
