
#include "math/matrix.h"
#include "include/matrix_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Matrix submatrix") {
  GIVEN("a matrix") {
    math::Matrix<3U, 3U> A{{{{1, 5, 0}, {-3, 2, 7}, {0, 6, -3}}}};
    WHEN("a submatrix is computed") {
      auto B = A.sub(0, 2);
      THEN("the values are correct") {
        const auto Expected = math::Matrix<2U, 2U>{{{{-3, 2}, {0, 6}}}};
        REQUIRE(ApproxEqual(Expected, B));
      }
    }
  }
  GIVEN("another matrix") {
    math::Matrix4 A{
        {{{-6, 1, 1, 6}, {-8, 5, 8, 6}, {-1, 0, 8, 2}, {-7, 1, -1, 1}}}};
    WHEN("a submatrix is computed") {
      auto B = A.sub(2, 1);
      THEN("the values are correct") {
        const auto Expected =
            math::Matrix<3U, 3U>{{{{-6, 1, 6}, {-8, 8, 6}, {-7, -1, 1}}}};
        REQUIRE(ApproxEqual(Expected, B));
      }
    }
  }
}
}  // namespace ray_tracer
