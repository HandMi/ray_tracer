#include "patterns/stripe.h"

namespace ray_tracer {
namespace patterns {

Color Stripe::at(const Point& point) const {
  if (static_cast<int>(std::floor(point.x())) % 2 == 0) {
    return color1;
  } else {
    return color2;
  }
}
}  // namespace patterns
}  // namespace ray_tracer