
#include "math/matrix.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Matrix creation") {
  GIVEN("a 4x4 array") {
    std::array<std::array<Decimal, 4U>, 4U> data{{{1, 2, 3, 4},
                                                  {5.5, 6.5, 7.5, 8.5},
                                                  {9, 10, 11, 12},
                                                  {13.5, 14.5, 15.5, 16.5}}};
    WHEN("a matrix is created") {
      math::Matrix<4U, 4U> mat(data);
      THEN("the values are correct") {
        REQUIRE(mat(0, 0) == Approx(1));
        REQUIRE(mat(0, 3) == Approx(4));
        REQUIRE(mat(3, 2) == Approx(15.5));
      }
    }
  }
}
}  // namespace ray_tracer
