
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Tuple scaling test") {
  GIVEN("a point") {
    Point a{-4, 6, 8};
    WHEN("it is scaled") {
      a.scale(2, 3, 4);
      THEN("the values are correct") {
        const Point Expected{-8, 18, 32};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
  }
  GIVEN("a vector") {
    Vector a{-4, 6, 8};
    WHEN("it is scaled") {
      a.scale(2, 3, 4);
      THEN("the values are correct") {
        const Vector Expected{-8, 18, 32};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
  }
  GIVEN("a vector") {
    Vector a{-4, 6, 8};
    WHEN("it is reflected") {
      a.scale(-1, 1, 1);
      THEN("the values are correct") {
        const Vector Expected{4, 6, 8};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
  }
}
}  // namespace ray_tracer
