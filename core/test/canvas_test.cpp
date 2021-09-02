
#include "canvas.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Canvas creation") {
  GIVEN("width and height") {
    std::size_t expected_width = 1024U;
    std::size_t expected_height = 768U;
    WHEN("a canvas is created") {
      Canvas canvas(expected_width, expected_height);
      THEN("the width and height are correctly set") {
        REQUIRE(canvas.width == expected_width);
        REQUIRE(canvas.height == expected_height);
        REQUIRE(canvas.get(0, 0).r == Approx(0));
        REQUIRE(canvas.get(0, 0).g == Approx(0));
        REQUIRE(canvas.get(0, 0).b == Approx(0));
      }
    }
  }
  GIVEN("a canvas") {
    Canvas canvas(1024U, 768U);
    WHEN("an arbitrary pixel is set") {
      canvas.set(23, 456, Color{23., 12., 0.5});
      THEN("the color is correct") {
        REQUIRE(canvas.get(23, 456).r == Approx(23.));
        REQUIRE(canvas.get(23, 456).g == Approx(12.));
        REQUIRE(canvas.get(23, 456).b == Approx(0.5));
      }
    }
  }
}
}  // namespace ray_tracer
