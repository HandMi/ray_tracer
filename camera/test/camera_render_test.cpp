#include "camera/camera.h"
#include "common/constants.h"
#include "core/view_transform.h"
#include "utils/tuple_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Rendering a world with a camera") {
  GIVEN("a camera and the default world") {
    Camera camera(11, 11, PI / 2.);
    const Point from(0, 0., -5);
    const Point to(0, 0, 0);
    const Vector up(0, 1, 0);
    camera.set_transform(view_transform(from, to, up));
    const auto world = World::Default();
    WHEN("the world is rendered") {
      const auto image = camera.render(world);
      THEN("the result is correct") {
        REQUIRE(ApproxEqual(image.get(5, 5), Color(0.38066, 0.47583, 0.2855)));
      }
    }
  }
}
}  // namespace ray_tracer
