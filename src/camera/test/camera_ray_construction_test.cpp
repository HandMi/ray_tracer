#include "camera/camera.h"
#include "common/constants.h"
#include "core/transform.h"
#include "utils/tuple_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Constructing a ray through the center of the canvas") {
  GIVEN("a camera") {
    Camera camera(201, 101, PI / 2.);
    WHEN("the ray through a point is computed") {
      const auto ray = camera.ray_to_pixel(100, 50);
      THEN("the result is correct") {
        REQUIRE(ApproxEqual(ray.origin, Point(0, 0, 0)));
        REQUIRE(ApproxEqual(ray.direction, Vector(0, 0, -1)));
      }
    }
  }
}
SCENARIO("Constructing a ray through a corner of the canvas") {
  GIVEN("a camera") {
    Camera camera(201, 101, PI / 2.);
    WHEN("the ray through a point is computed") {
      const auto ray = camera.ray_to_pixel(0, 0);
      THEN("the result is correct") {
        REQUIRE(ApproxEqual(ray.origin, Point(0, 0, 0)));
        REQUIRE(ApproxEqual(ray.direction, Vector(0.66519, 0.33259, -0.66851)));
      }
    }
  }
}
SCENARIO("Constructing a ray when the camera is transformed") {
  GIVEN("a camera") {
    Camera camera(201, 101, PI / 2.);
    Transform transform = Identity().translate(0., -2., 5.).rotate_y(PI / 4.);
    camera.set_transform(transform);
    WHEN("the ray through a point is computed") {
      const auto ray = camera.ray_to_pixel(100, 50);
      THEN("the result is correct") {
        REQUIRE(ApproxEqual(ray.origin, Point(0, 2, -5)));
        REQUIRE(ApproxEqual(ray.direction, Vector(std::sqrt(2.) / 2., 0.,
                                                  -std::sqrt(2.) / 2.)));
      }
    }
  }
}
}  // namespace ray_tracer
