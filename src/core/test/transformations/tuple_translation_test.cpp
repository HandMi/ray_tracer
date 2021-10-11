
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Tuple translation test") {
  GIVEN("a point") {
    Point a{-3, 4, 5};
    WHEN("it is translated") {
      a.translate(5, -3, 2);
      THEN("the values are correct") {
        Point Expected{2, 1, 7};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
        AND_WHEN("it is translated back") {
          a.translate(-5, 3, -2);
          THEN("the values are as before") {
            Expected = Point{-3, 4, 5};
            REQUIRE(a(0) == Approx(Expected(0)));
            REQUIRE(a(1) == Approx(Expected(1)));
            REQUIRE(a(2) == Approx(Expected(2)));
          }
        }
      }
    }
  }
  GIVEN("a vector") {
    Vector a{-3, 4, 5};
    WHEN("it is translated") {
      a.translate(5, -3, 2);
      THEN("it is not affected") {
        Vector Expected{-3, 4, 5};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
  }
}
}  // namespace ray_tracer
