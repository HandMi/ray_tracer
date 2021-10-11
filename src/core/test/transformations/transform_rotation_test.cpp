
#include "core/transform.h"
#include "core/tuple.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Transform rotation test") {
  GIVEN("a point") {
    Point a{0, 1, 0};
    WHEN("it is rotated by an eighth rotation around the x axis") {
      Transform A = Identity().rotate_x(PI / 4.);
      a = A * a;
      THEN("the values are correct") {
        const Point Expected{0, std::sqrt(2.) / 2., std::sqrt(2.) / 2.};
        REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
        REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
        REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
        AND_WHEN("it is rotated back") {
          a = A.Inv() * a;
          THEN("the values are correct") {
            const Point Expected{0, 1, 0};
            REQUIRE(a(0) == Approx(Expected(0)).margin(1e-12));
            REQUIRE(a(1) == Approx(Expected(1)).margin(1e-12));
            REQUIRE(a(2) == Approx(Expected(2)).margin(1e-12));
          }
        }
      }
    }
  }
}
}  // namespace ray_tracer
