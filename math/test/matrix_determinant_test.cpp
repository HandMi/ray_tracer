
#include "utils/matrix_test_helper.h"
#include "math/matrix.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Matrix determinant") {
  GIVEN("a 3x3 matrix") {
    math::Matrix<3U, 3U> A{{{{1, 2, 6}, {-5, 8, -4}, {2, 6, 4}}}};
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 0);
      THEN("the value is correct") { REQUIRE(B == Approx(56.)); }
    }
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 1);
      THEN("the value is correct") { REQUIRE(B == Approx(12.)); }
    }
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 2);
      THEN("the value is correct") { REQUIRE(B == Approx(-46.)); }
    }
    WHEN("the determinant is computed") {
      auto B = A.determinant();
      THEN("the value is correct") { REQUIRE(B == Approx(-196.)); }
    }
  }
  GIVEN("a 4x4 matrix") {
    math::Matrix<4U, 4U> A{
        {{{-2, -8, 3, 5}, {-3, 1, 7, 3}, {1, 2, -9, 6}, {-6, 7, 7, -9}}}};
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 0);
      THEN("the value is correct") { REQUIRE(B == Approx(690.)); }
    }
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 1);
      THEN("the value is correct") { REQUIRE(B == Approx(447.)); }
    }
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 2);
      THEN("the value is correct") { REQUIRE(B == Approx(210.)); }
    }
    WHEN("a cofactor is computed") {
      auto B = A.cofactor(0, 3);
      THEN("the value is correct") { REQUIRE(B == Approx(51.)); }
    }
    WHEN("the determinant is computed") {
      auto B = A.determinant();
      THEN("the value is correct") { REQUIRE(B == Approx(-4071)); }
    }
  }
}
}  // namespace ray_tracer
