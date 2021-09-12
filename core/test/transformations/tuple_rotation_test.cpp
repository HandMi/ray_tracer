
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cmath>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Tuple rotation test") {
  GIVEN("a point") {
    Point a{0, 1, 0};
    WHEN("it is rotated by an eighth rotation around the x axis") {
      a.rotate_x(PI / 4.);
      THEN("the values are correct") {
        const Point Expected{0, std::sqrt(2.) / 2., std::sqrt(2.) / 2.};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
    WHEN("it is rotated by a quarter rotation around the x axis") {
      a.rotate_x(PI / 2.);
      THEN("the values are correct") {
        const Point Expected{0, 0, 1};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
  }
  GIVEN("a point") {
    Point a{0, 0, 1};
    WHEN("it is rotated by an eighth rotation around the y axis") {
      a.rotate_y(PI / 4.);
      THEN("the values are correct") {
        const Point Expected{std::sqrt(2.) / 2., 0., std::sqrt(2.) / 2.};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
    WHEN("it is rotated by a quarter rotation around the y axis") {
      a.rotate_y(PI / 2.);
      THEN("the values are correct") {
        const Point Expected{1, 0, 0};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
  }
  GIVEN("a point") {
    Point a{0, 1, 0};
    WHEN("it is rotated by an eighth rotation around the z axis") {
      a.rotate_z(PI / 4.);
      THEN("the values are correct") {
        const Point Expected{-std::sqrt(2.) / 2., std::sqrt(2.) / 2., 0.};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
    WHEN("it is rotated by a quarter rotation around the z axis") {
      a.rotate_z(PI / 2.);
      THEN("the values are correct") {
        const Point Expected{-1, 0, 0};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
      }
    }
  }  
}
}  // namespace ray_tracer
