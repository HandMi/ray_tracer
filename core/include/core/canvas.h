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
  Canvas(UInteger width, UInteger height) : width{width}, height{height} {
    grid = Grid(height, Row(width, {0., 0., 0.}));
  };
  const UInteger width{};
  const UInteger height{};

  Color get(const UInteger i, const UInteger j) const {
    if (i < width && j < height) {
      return grid[j][i];
    } else {
      return {};
    }
  }

  void set(const UInteger i, const UInteger j, const Color color) {
    if (i < width && j < height) {
      grid[j][i] = color;
    }
  }

  void setAll(const Color color) {
    for (auto& row : grid) {
      for (auto& c : row) {
        c = color;
      }
    }
  }
};
}  // namespace ray_tracer

#endif
