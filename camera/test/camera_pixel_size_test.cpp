#include "camera/camera.h"
#include "common/constants.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("The pixel size for a horizontal canvas") {
  GIVEN("a camera with a horizontal canvas") {
    Camera camera(200, 125, PI / 2.);
    WHEN("the pixel size is computed") {
      const auto pixel_size = camera.get_pixel_size();
      THEN("the result is correct") { REQUIRE(pixel_size == Approx(0.01)); }
    }
  }
}
SCENARIO("The pixel size for a vertical canvas") {
  GIVEN("a camerawith a vertical canvas") {
    Camera camera(125, 200, PI / 2.);
    WHEN("the pixel size is computed") {
      const auto pixel_size = camera.get_pixel_size();
      THEN("the result is correct") { REQUIRE(pixel_size == Approx(0.01)); }
    }
  }
}
}  // namespace ray_tracer
