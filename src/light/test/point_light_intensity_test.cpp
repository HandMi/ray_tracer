
#include "light/point_light.h"
#include "world/world.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Point lights evaluate the light intensity at a given point") {
  GIVEN("the default world and a point light") {
    const auto world = World::Default();
    const PointLight light{Point{-10., 10., -10.}, Color{1., 1., 1.}};
    WHEN("the intensity at a point in the light is calculated") {
      const Point point{0., 1.0001, 0.};
      const auto intensity = light.intensity_at(world, point);
      THEN("the value is 1.") { REQUIRE(intensity == 1.0); }
    }
    WHEN("the intensity at a point in the shadow is calculated") {
      const Point point{0., 0., 1.0001};
      const auto intensity = light.intensity_at(world, point);
      THEN("the value is 0.") { REQUIRE(intensity == 0.); }
    }
  }
}
}  // namespace ray_tracer
