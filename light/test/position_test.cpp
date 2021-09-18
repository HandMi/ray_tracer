
#include "light/ray.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Position test") {
  GIVEN("a ray") {
    const Point origin{2, 3, 4};
    const Vector direction{1, 0, 0};
    const Ray ray{origin, direction};
    WHEN("a position is calculated") {
      const auto pos = position(ray, 0.);
      THEN("the values are correctly transfered") {
        const Point expected(2., 3., 4.);
        REQUIRE(pos.x() == Approx(expected.x()));
        REQUIRE(pos.y() == Approx(expected.y()));
        REQUIRE(pos.z() == Approx(expected.z()));
      }
    }
    WHEN("a position is calculated") {
      const auto pos = position(ray, 1.);
      THEN("the values are correctly transfered") {
        const Point expected(3., 3., 4.);
        REQUIRE(pos.x() == Approx(expected.x()));
        REQUIRE(pos.y() == Approx(expected.y()));
        REQUIRE(pos.z() == Approx(expected.z()));
      }
    }
    WHEN("a position is calculated") {
      const auto pos = position(ray, -1.);
      THEN("the values are correctly transfered") {
        const Point expected(1., 3., 4.);
        REQUIRE(pos.x() == Approx(expected.x()));
        REQUIRE(pos.y() == Approx(expected.y()));
        REQUIRE(pos.z() == Approx(expected.z()));
      }
    }
    WHEN("a position is calculated") {
      const auto pos = position(ray, 2.5);
      THEN("the values are correctly transfered") {
        const Point expected(4.5, 3., 4.);
        REQUIRE(pos.x() == Approx(expected.x()));
        REQUIRE(pos.y() == Approx(expected.y()));
        REQUIRE(pos.z() == Approx(expected.z()));
      }
    }
  }
}
}  // namespace ray_tracer
