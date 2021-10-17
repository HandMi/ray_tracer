#include "shapes/plane.h"
#include "utils/tuple_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("The normal of a plane is constant everywhere") {
  GIVEN("a plane") {
    const auto sphere = shapes::Plane::create();
    WHEN("the normal is computed") {
      const auto normal1 = sphere->normal_at({0, 0, 0});
      const auto normal2 = sphere->normal_at({10, 0, -10});
      const auto normal3 = sphere->normal_at({-5, 0, 150});
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(normal1, Vector{0, 1, 0}));
        REQUIRE(ApproxEqual(normal2, Vector{0, 1, 0}));
        REQUIRE(ApproxEqual(normal3, Vector{0, 1, 0}));
      }
    }
  }
}
}  // namespace ray_tracer
