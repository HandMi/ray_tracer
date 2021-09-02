#ifndef CORE_INCLUDE_CANVAS_H
#define CORE_INCLUDE_CANVAS_H

#include "color.h"
#include <vector>

namespace ray_tracer {
class Canvas {
  using Row = std::vector<Color>;
  using Grid = std::vector<Row>;

 private:
  Grid grid{};

 public:
  Canvas() = default;
  Canvas(std::size_t width, std::size_t height) : width{width}, height{height} {
    grid = Grid(height, Row(width, {0., 0., 0.}));
  };
  const std::size_t width{};
  const std::size_t height{};
  Color get(const std::size_t i, const std::size_t j) const {
    if (i < width && j < height) {
      return grid[j][i];
    } else {
      return {};
    }
  }
  void set(const std::size_t i, const std::size_t j, const Color color) {
    if (i < width && j < height) {
      grid[j][i] = color;
    }
  }
};
}  // namespace ray_tracer

#endif
