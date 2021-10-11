#include "light/point_light.h"
#include "world/world.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("There is no shadow when nothing is collinear with point and light") {
  GIVEN("a world and a point") {
    auto world = World::Default();
    const Point light_position{-10., 10., -10.};
    const Point point{0., 10., 0.};
    WHEN("it is tested for shadow") {
      const auto is_shadowed = world.is_shadowed(point, light_position);
      THEN("the result is correct") { REQUIRE(is_shadowed == false); }
    }
  }
}

SCENARIO("The shadow when an object is between the point and the light") {
  GIVEN("a world and a point") {
    auto world = World::Default();
    const Point light_position{-10., 10., -10.};
    const Point point{10., -10., 10.};
    WHEN("it is tested for shadow") {
      const auto is_shadowed = world.is_shadowed(point, light_position);
      THEN("the result is correct") { REQUIRE(is_shadowed == true); }
    }
  }
}

SCENARIO("There is no shadow when an object is behind the light") {
  GIVEN("a world and a point") {
    auto world = World::Default();
    const Point light_position{-10., 10., -10.};
    const Point point{-20., 20., -20.};
    WHEN("it is tested for shadow") {
      const auto is_shadowed = world.is_shadowed(point, light_position);
      THEN("the result is correct") { REQUIRE(is_shadowed == false); }
    }
  }
}

SCENARIO("There is no shadow when an object is behind the point") {
  GIVEN("a world and a point") {
    auto world = World::Default();
    const Point light_position{-10., 10., -10.};
    const Point point{-2., 2., -2.};
    WHEN("it is tested for shadow") {
      const auto is_shadowed = world.is_shadowed(point, light_position);
      THEN("the result is correct") { REQUIRE(is_shadowed == false); }
    }
  }
}
}  // namespace ray_tracer
