
#include "core/transform.h"
#include "light/ray.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Translating a ray") {
  GIVEN("a ray and a translation") {
    const Ray ray{{1, 2, 3}, {0, 1, 0}};
    const Transform transform = Identity().translate(3, 4, 5);
    WHEN("the transformation is applied") {
      const auto new_ray = transform * ray;
      THEN("the values are correctly transfered") {
        REQUIRE(new_ray.origin.x() == Approx(4));
        REQUIRE(new_ray.origin.y() == Approx(6));
        REQUIRE(new_ray.origin.z() == Approx(8));
        REQUIRE(new_ray.direction.x() == Approx(0));
        REQUIRE(new_ray.direction.y() == Approx(1));
        REQUIRE(new_ray.direction.z() == Approx(0));
      }
    }
  }
}

SCENARIO("Scaling a ray") {
  GIVEN("a ray and a scaling") {
    const Ray ray{{1, 2, 3}, {0, 1, 0}};
    const Transform transform = Identity().scale(2, 3, 4);
    WHEN("the transformation is applied") {
      const auto new_ray = transform * ray;
      THEN("the values are correctly transfered") {
        REQUIRE(new_ray.origin.x() == Approx(2));
        REQUIRE(new_ray.origin.y() == Approx(6));
        REQUIRE(new_ray.origin.z() == Approx(12));
        REQUIRE(new_ray.direction.x() == Approx(0));
        REQUIRE(new_ray.direction.y() == Approx(3));
        REQUIRE(new_ray.direction.z() == Approx(0));
      }
    }
  }
}
}  // namespace ray_tracer
