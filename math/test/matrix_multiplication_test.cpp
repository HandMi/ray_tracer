
#include "include/matrix_test_helper.h"
#include "math/matrix.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Matrix multiplication") {
  GIVEN("two matrices") {
    const math::Matrix4 A{
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}}}};
    const math::Matrix4 B{
        {{{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 6, 5}, {1, 2, 7, 8}}}};
    WHEN("they are multiplied") {
      const auto C = A * B;
      THEN("the values are correct") {
        const auto Expected = math::Matrix4{{{{20, 22, 50, 48},
                                              {44, 54, 114, 108},
                                              {40, 58, 110, 102},
                                              {16, 26, 46, 42}}}};
        REQUIRE(ApproxEqual(Expected, C));
      }
    }
  }
  GIVEN("a matrix and the identity matrix") {
    const math::Matrix4 A{
        {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}}}};
    const math::Matrix4 B = math::Identity4();
    WHEN("they are multiplied") {
      const auto C = A * B;
      THEN("the matrix is the same") { REQUIRE(ApproxEqual(A, C)); }
    }
  }
}

SCENARIO("Matrix and vector multiplication") {
  GIVEN("a matrix and a vector") {
    const math::Matrix4 A{
        {{{1, 2, 3, 4}, {2, 4, 4, 2}, {8, 6, 4, 1}, {0, 0, 0, 1}}}};
    const Vector b{1, 2, 3};

    WHEN("they are multiplied") {
      const auto c = A * b;
      THEN("the values are correct") {
        const auto Expected = Vector{14, 22, 32};
        REQUIRE(c(0) == Approx(Expected(0)));
        REQUIRE(c(1) == Approx(Expected(1)));
        REQUIRE(c(2) == Approx(Expected(2)));
        REQUIRE(c(3) == Approx(Expected(3)));
      }
    }
  }
}
}  // namespace ray_tracer
