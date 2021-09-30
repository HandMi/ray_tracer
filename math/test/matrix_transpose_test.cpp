
#include "utils/matrix_test_helper.h"
#include "math/matrix.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Matrix transpose") {
  GIVEN("a matrix") {
    math::Matrix4 A{{{{0, 9, 3, 0}, {9, 8, 0, 8}, {1, 8, 5, 3}, {0, 0, 5, 8}}}};
    WHEN("it is transposed") {
      A.T();
      THEN("the values are correct") {
        const auto Expected = math::Matrix4{{{{0, 9, 1, 0},
                                              {9, 8, 8, 0},
                                              {3, 0, 5, 5},
                                              {0, 8, 3, 8}}}};
        REQUIRE(ApproxEqual(Expected, A));
      }
    }
  }
  GIVEN("the identity matrix") {
    auto I = math::Identity4();
    WHEN("it is transposed") {
      I.T();
      THEN("it is mapped to itself") {
        const auto Expected = math::Identity4();
        REQUIRE(ApproxEqual(Expected, I));
      }
    }
  }
}
}  // namespace ray_tracer
