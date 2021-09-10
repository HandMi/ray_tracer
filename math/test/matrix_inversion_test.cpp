
#include "include/matrix_test_helper.h"
#include "math/matrix.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Matrix inverse") {
  GIVEN("a matrix") {
    math::Matrix4 A{
        {{{-5, 2, 6, -8}, {1, -5, 1, 8}, {7, 7, -6, -7}, {1, -3, 7, 4}}}};
    WHEN("it is inverse") {
      auto B = A.Inv();
      THEN("the values are correct") {
        const auto Expected =
            math::Matrix4{{{{0.21805, 0.45113, 0.24060, -0.04511},
                            {-0.80827, -1.45677, -0.44361, 0.52068},
                            {-0.07895, -0.22368, -0.05263, 0.19737},
                            {-0.52256, -0.81391, -0.30075, 0.30639}}}};
        REQUIRE(ApproxEqual(Expected, B));
      }
    }
  }
  GIVEN("the identity matrix") {
    auto I = math::Identity4();
    WHEN("it is inverted") {
      auto B = I.Inv();
      THEN("it is mapped to itself") {
        const auto Expected = math::Identity4();
        REQUIRE(ApproxEqual(Expected, B));
      }
    }
  }
  GIVEN("the 0 matrix") {
    math::Matrix4 A{};
    WHEN("it is inverted") {
      THEN("an exception is thrown") { REQUIRE_THROWS(A.Inv()); }
    }
  }
  GIVEN("two matrices") {
    const math::Matrix4 A{
        {{{1, 2, 3, 4}, {5, 6, 7, 2}, {9, 4, 7, 6}, {5, 4, 3, 2}}}};
    const math::Matrix4 B{
        {{{-2, 1, 2, 3}, {3, 2, 1, -1}, {4, 3, 4, 5}, {1, 2, 3, 8}}}};
    WHEN("they are multiplied and ivnerted") {
      const auto ProductInverse = (A*B).Inv();
      THEN("the values are is the same as the reverse product of the inverses") {
      const auto InverseProduct = (B.Inv()*A.Inv());
        REQUIRE(ApproxEqual(InverseProduct, ProductInverse));
      }
    }
  }
}
}  // namespace ray_tracer
