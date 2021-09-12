
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

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
