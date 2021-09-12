
#include "core/transform.h"
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Transform scaling test") {
  GIVEN("a point") {
    Point a{-4, 6, 8};
    WHEN("a scaling transform is applied to it") {
      Transform A = Identity().scale(2, 3, 4);
      const auto b = A * a;
      THEN("the values are correct") {
        const Point Expected{-8, 18, 32};
        REQUIRE(b(0) == Approx(Expected(0)));
        REQUIRE(b(1) == Approx(Expected(1)));
        REQUIRE(b(2) == Approx(Expected(2)));
      }
    }
  }
}
}  // namespace ray_tracer
