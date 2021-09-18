#ifndef SHAPES_INCLUDE_MATERIAL_H
#define SHAPES_INCLUDE_MATERIAL_H

#include "core/transform.h"
#include "core/tuple.h"
#include <memory>
#include <optional>

namespace ray_tracer {
namespace shapes {

class Material : public std::enable_shared_from_this<Material> {
 private:
  Material() = default;

 public:
  template <typename... T>
  static std::shared_ptr<Material> create(T&&... args) {
    return std::shared_ptr<Material>(new Material(std::forward<T>(args)...));
  }
  Decimal ambient{0.1};
  Decimal diffuse{0.9};
  Decimal specula{0.9};
  Decimal shininess{200.};
};

}  // namespace shapes
}  // namespace ray_tracer

#endif
