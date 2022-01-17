#ifndef SHAPES_INCLUDE_STRIPE_H
#define SHAPES_INCLUDE_STRIPE_H

#include "i_pattern.h"

namespace ray_tracer {
namespace patterns {

class Stripe : public IPattern {
  Color color1{};
  Color color2{};

 protected:
  Stripe() = default;
  Stripe(const Color& color1, const Color& color2)
      : IPattern{}, color1(color1), color2(color2){};

 public:
  template <typename... T>
  static std::shared_ptr<const IPattern> create(T&&... args) {
    return std::shared_ptr<const IPattern>(
        new const Stripe(std::forward<T>(args)...));
  };
  Color at(const Point& point) const override;
};
}  // namespace patterns
}  // namespace ray_tracer

#endif
