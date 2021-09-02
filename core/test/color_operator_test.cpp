
#include "color.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Color additions") {
  GIVEN("two color") {
    Color color1{0.9, 0.6, 0.75};
    Color color2{0.7, 0.1, 0.25};
    WHEN("they are added") {
      auto result = color1 + color2;
      THEN("the result is correct") {
        REQUIRE(result.r == Approx(1.6));
        REQUIRE(result.g == Approx(0.7));
        REQUIRE(result.b == Approx(1.0));
      }
    }
    WHEN("one is directly added to the other") {
      color1 += color2;
      THEN("the result is correct") {
        REQUIRE(color1.r == Approx(1.6));
        REQUIRE(color1.g == Approx(0.7));
        REQUIRE(color1.b == Approx(1.0));
      }
    }
  }
}

SCENARIO("Color subtraction") {
  GIVEN("two color") {
    Color color1{0.9, 0.6, 0.75};
    Color color2{0.7, 0.1, 0.25};
    WHEN("they are subtracted") {
      auto result = color1 - color2;
      THEN("the result is correct") {
        REQUIRE(result.r == Approx(0.2));
        REQUIRE(result.g == Approx(0.5));
        REQUIRE(result.b == Approx(0.5));
      }
    }
    WHEN("one is directly subtracted from the other") {
      color1 -= color2;
      THEN("the result is correct") {
        REQUIRE(color1.r == Approx(0.2));
        REQUIRE(color1.g == Approx(0.5));
        REQUIRE(color1.b == Approx(0.5));
      }
    }
  }
}

SCENARIO("Color scalar multiplication") {
  GIVEN("a color and a scalar") {
    Color color{0.2, 0.3, 0.4};
    Decimal a{2.};
    WHEN("they are multiplied") {
      auto result = a * color;
      THEN("the result is correct") {
        REQUIRE(result.r == Approx(0.4));
        REQUIRE(result.g == Approx(0.6));
        REQUIRE(result.b == Approx(0.8));
      }
    }
    WHEN("one is directly subtracted from the other") {
      color *= a;
      THEN("the result is correct") {
        REQUIRE(color.r == Approx(0.4));
        REQUIRE(color.g == Approx(0.6));
        REQUIRE(color.b == Approx(0.8));
      }
    }
  }
}

SCENARIO("Color Hadamard multiplication") {
  GIVEN("two color") {
    Color color1{1, 0.2, 0.4};
    Color color2{0.9, 1, 0.1};
    WHEN("they are multiplied") {
      auto result = color1 * color2;
      THEN("the result is correct") {
        REQUIRE(result.r == Approx(0.9));
        REQUIRE(result.g == Approx(0.2));
        REQUIRE(result.b == Approx(0.04));
      }
    }
  }
}
}  // namespace ray_tracer
