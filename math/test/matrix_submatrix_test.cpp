
#include "math/matrix.h"
#include "utils/matrix_test_helper.h"
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
  GIVEN("a matrix") {
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
  GIVEN("a matrix") {
    math::Matrix<3U, 3U> A{{{{3, 5, 0}, {2, -1, -7}, {6, -1, 5}}}};
    WHEN("a submatrix is computed") {
      auto B = A.sub(1, 0);
      THEN("the determinant is correct") {
        const Decimal Expected = 25.;
        REQUIRE(B.determinant() == Approx(Expected));
        AND_THEN("the determinant is equal to the minor") {
          REQUIRE(A.minorant(1, 0) == Approx(Expected));
        }
      }
    }
  }
  GIVEN("a matrix") {
    math::Matrix<3U, 3U> A{{{{3, 5, 0}, {2, -1, -7}, {6, -1, 5}}}};
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 0);
      THEN("the result is correct") {
        const Decimal Expected = -12.;
        REQUIRE(B == Approx(Expected));
      }
    }
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(1, 0);
      THEN("the result is correct") {
        const Decimal Expected = -25.;
        REQUIRE(B == Approx(Expected));
      }
    }
  }
}
}  // namespace ray_tracer
