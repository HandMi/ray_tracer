
#include "light/ray.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Ray creation") {
  GIVEN("an origin and a direction") {
    const Point origin{1, 2, 3};
    const Vector direction{4, 5, 6};
    WHEN("a ray is created") {
      const Ray ray{origin, direction};
      THEN("the values are correctly transfered") {
        REQUIRE(ray.origin.x() == Approx(origin.x()));
        REQUIRE(ray.origin.y() == Approx(origin.y()));
        REQUIRE(ray.origin.z() == Approx(origin.z()));
        REQUIRE(ray.direction.x() == Approx(direction.x()));
        REQUIRE(ray.direction.y() == Approx(direction.y()));
        REQUIRE(ray.direction.z() == Approx(direction.z()));
      }
    }
  }
}
}  // namespace ray_tracer
