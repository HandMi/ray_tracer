
#include "tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {
namespace core {

SCENARIO("Vector length") {
  GIVEN("a vector") {
    const Vector vector(2., -10., 11.);
    WHEN("the length is computed") {
      const auto result = vector.length();
      THEN("the result is correct") { REQUIRE(result == Approx(15.)); }
    }
  }
}

SCENARIO("Vector normalization") {
  GIVEN("a vector") {
    Vector vector(2., -10., 11.);
    WHEN("it is normalized") {
      vector.normalize();
      THEN("the length is one") {
        const auto result = vector.length();
        REQUIRE(result == Approx(1.));
        REQUIRE(vector.x == Approx(2. / 15.));
        REQUIRE(vector.y == Approx(-10. / 15.));
        REQUIRE(vector.z == Approx(11. / 15.));
      }
    }
  }
}

SCENARIO("Vector dot product") {
  GIVEN("two vectors") {
    const Vector vector1(3., -2., 5.);
    const Vector vector2(-2., 3., 1.);
    WHEN("they are dot multiplied") {
      const auto result = dot(vector1, vector2);
      THEN("the result is correct") {
        REQUIRE(result == Approx(-7.));
      }
    }
  }
}

SCENARIO("Vector cross product") {
  GIVEN("two vectors") {
    const Vector vector1(1., 2., 3.);
    const Vector vector2(2., 3., 4.);
    WHEN("they are cross multiplied") {
      const auto result = cross(vector1, vector2);
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(-1.));
        REQUIRE(result.y == Approx(2.));
        REQUIRE(result.z == Approx(-1.));
      }
    }
    WHEN("they are cross multiplied in inverse order") {
      const auto result = cross(vector2, vector1);
      THEN("the result is inverted") {
        REQUIRE(result.x == Approx(1.));
        REQUIRE(result.y == Approx(-2.));
        REQUIRE(result.z == Approx(1.));
      }
    }
  }
}
}  // namespace core
}  // namespace ray_tracer