
#include "tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {
namespace core {

SCENARIO("Tuple addition") {
  GIVEN("two vectors") {
    const Vector vector1(3., -2., 5.);
    const Vector vector2(-2., 3., 1.);
    WHEN("they are subtracted") {
      const auto result = vector2 - vector1;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(vector2.x - vector1.x));
        REQUIRE(result.y == Approx(vector2.y - vector1.y));
        REQUIRE(result.z == Approx(vector2.z - vector1.z));
      }
    }
    WHEN("they are added") {
      const auto result = vector2 + vector1;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(vector2.x + vector1.x));
        REQUIRE(result.y == Approx(vector2.y + vector1.y));
        REQUIRE(result.z == Approx(vector2.z + vector1.z));
      }
    }
    WHEN("they one is added to the other") {
      auto result = vector1;
      result += vector2;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(vector2.x + vector1.x));
        REQUIRE(result.y == Approx(vector2.y + vector1.y));
        REQUIRE(result.z == Approx(vector2.z + vector1.z));
      }
    }
    WHEN("they one is subtracted from the other") {
      auto result = vector2;
      result -= vector1;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(vector2.x - vector1.x));
        REQUIRE(result.y == Approx(vector2.y - vector1.y));
        REQUIRE(result.z == Approx(vector2.z - vector1.z));
      }
    }
  }
  GIVEN("two points") {
    const Point point1(3, 2, 1);
    const Point point2(5, 6, 7);
    WHEN("they are subtracted") {
      const auto result = point2 - point1;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(point2.x - point1.x));
        REQUIRE(result.y == Approx(point2.y - point1.y));
        REQUIRE(result.z == Approx(point2.z - point1.z));
      }
    }
  }
  GIVEN("a point and a vector") {
    const Point point(3, 2, 1);
    const Vector vector(5, 6, 7);
    WHEN("they are subtracted") {
      const auto result = point - vector;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(point.x - vector.x));
        REQUIRE(result.y == Approx(point.y - vector.y));
        REQUIRE(result.z == Approx(point.z - vector.z));
      }
    }
    WHEN("they are added") {
      const auto result = point + vector;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(point.x + vector.x));
        REQUIRE(result.y == Approx(point.y + vector.y));
        REQUIRE(result.z == Approx(point.z + vector.z));
      }
    }
  }
}

SCENARIO("Tuple negation") {
  GIVEN("a vector") {
    const Vector vector(3., -2., 5.);
    WHEN("it is negated") {
      const auto result = -vector;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(-vector.x));
        REQUIRE(result.y == Approx(-vector.y));
        REQUIRE(result.z == Approx(-vector.z));
      }
    }
  }
}

SCENARIO("Tuple scalar multiplication") {
  GIVEN("a vector and a scalar") {
    const Vector vector(3., -2., 5.);
    const Decimal x{3.14};
    WHEN("they are multiplied") {
      const auto result = x * vector;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(x * vector.x));
        REQUIRE(result.y == Approx(x * vector.y));
        REQUIRE(result.z == Approx(x * vector.z));
      }
    }
    WHEN("they are multiplied in reverse order") {
      const auto result = vector * x;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(x * vector.x));
        REQUIRE(result.y == Approx(x * vector.y));
        REQUIRE(result.z == Approx(x * vector.z));
      }
    }
    WHEN("the vecor is directly scaled") {
      auto result = vector;
      result *= x;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(x * vector.x));
        REQUIRE(result.y == Approx(x * vector.y));
        REQUIRE(result.z == Approx(x * vector.z));
      }
    }
  }
}
SCENARIO("Tuple scalar division") {
  GIVEN("a vector and a scalar") {
    const Vector vector(3., -2., 5.);
    const Decimal x{3.14};
    WHEN("the vector is divided") {
      const auto result = vector / x;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(vector.x / x));
        REQUIRE(result.y == Approx(vector.y / x));
        REQUIRE(result.z == Approx(vector.z / x));
      }
    }
    WHEN("the vecor is directly scaled") {
      auto result = vector;
      result /= x;
      THEN("the result is correct") {
        REQUIRE(result.x == Approx(vector.x / x));
        REQUIRE(result.y == Approx(vector.y / x));
        REQUIRE(result.z == Approx(vector.z / x));
      }
    }
  }
}
}  // namespace core
}  // namespace ray_tracer