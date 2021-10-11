#include "core/tuple.h"
#include "utils/tuple_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Reflecting a vector approaching at 45°") {
  GIVEN("a Vector and a surface normal") {
    Vector v{1, -1, 0};
    Vector normal{0, 1, 0};
    WHEN("the vector is reflected") {
      const auto reflected = reflect(v, normal);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(reflected, Vector{1, 1, 0}));
      }
    }
  }
}
SCENARIO("Reflecting a vector off a slanted surface") {
  GIVEN("a Vector and a surface normal") {
    Vector v{0, -1, 0};
    Vector normal{std::sqrt(2.) / 2., std::sqrt(2.) / 2., 0};
    WHEN("the vector is reflected") {
      const auto reflected = reflect(v, normal);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(reflected, Vector{1, 0, 0}));
      }
    }
  }
}
}  // namespace ray_tracer