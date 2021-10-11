
#include "core/transform.h"
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Transform chaining test") {
  GIVEN("a point") {
    Point a{1, 0, 1};
    WHEN("transformations are chained") {
      Transform A = Identity().rotate_x(PI/2.).scale(5., 5., 5.).translate(10., 5., 7.);
      const auto b = A * a;
      THEN("the values are correct") {
        const Point Expected{15., 0., 7.};
        REQUIRE(b(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(b(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(b(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
    WHEN("transformations are directly applied") {
      a.rotate_x(PI/2.).scale(5., 5., 5.).translate(10., 5., 7.);
      THEN("the values are correct") {
        const Point Expected{15., 0., 7.};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
  }
}
}  // namespace ray_tracer
