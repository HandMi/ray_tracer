
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cmath>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Tuple shearing test") {
  GIVEN("a point") {
    Point a{2, 3, 4};
    WHEN("a shearing transformation moves x in proportion to y") {
      a.shear(1., 0., 0., 0., 0., 0.);
      THEN("the values are correct") {
        const Point Expected{5., 3., 4.};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
    WHEN("a shearing transformation moves x in proportion to z") {
      a.shear(0., 1., 0., 0., 0., 0.);
      THEN("the values are correct") {
        const Point Expected{6., 3., 4.};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
    WHEN("a shearing transformation moves y in proportion to x") {
      a.shear(0., 0., 1., 0., 0., 0.);
      THEN("the values are correct") {
        const Point Expected{2., 5., 4.};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
    WHEN("a shearing transformation moves y in proportion to z") {
      a.shear(0., 0., 0., 1., 0., 0.);
      THEN("the values are correct") {
        const Point Expected{2., 7., 4.};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
    WHEN("a shearing transformation moves z in proportion to x") {
      a.shear(0., 0., 0., 0., 1., 0.);
      THEN("the values are correct") {
        const Point Expected{2., 3., 6.};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
    WHEN("a shearing transformation moves z in proportion to y") {
      a.shear(0., 0., 0., 0., 0., 1.);
      THEN("the values are correct") {
        const Point Expected{2., 3., 7.};
        REQUIRE(a(0) == Approx(Expected(0)));
        REQUIRE(a(1) == Approx(Expected(1)));
        REQUIRE(a(2) == Approx(Expected(2)));
      }
    }
  }
}
}  // namespace ray_tracer
