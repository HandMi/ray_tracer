#include "core/utils.h"
#include "world/world.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("he color when a ray misses") {
  GIVEN("a world and a ray that misses") {
    auto world = world::World::Default();
    const Ray ray{{0., 0., -5.}, {0., 1., 0.}};
    WHEN("the color is computed") {
      const auto color = world.color_at(ray);
      THEN("the color is black") {
        REQUIRE(ApproxEqual(color, Colors::Black));
      }
    }
  }
}
}  // namespace ray_tracer
