
#include "core/view_transform.h"
#include "core/transform.h"
#include "utils/matrix_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("The transformation matrix for the default orientation") {
  GIVEN("the default view transformation") {
    const Point from{0, 0, 0};
    const Point to{0, 0, -1};
    const Vector up{0, 1, 0};
    WHEN("the view transform is computed") {
      const auto view_transformation = view_transform(from, to, up);
      THEN("it is the identity matrix") {
        REQUIRE(ApproxEqual(view_transformation, Identity()));
      }
    }
  }
}
SCENARIO("A view transformation matrix looking in positive z direction") {
  GIVEN("a view transformation") {
    const Point from{0, 0, 0};
    const Point to{0, 0, 1};
    const Vector up{0, 1, 0};
    WHEN("the view transform is computed") {
      const auto view_transformation = view_transform(from, to, up);
      THEN("it swaps front and back and left and right") {
        const Transform expected = Identity().scale(-1, 1, -1);
        REQUIRE(ApproxEqual(view_transformation, expected));
      }
    }
  }
}
SCENARIO("The view transformation moves the world") {
  GIVEN("a view transformation") {
    const Point from{0, 0, 8};
    const Point to{0, 0, 0};
    const Vector up{0, 1, 0};
    WHEN("the view transform is computed") {
      const auto view_transformation = view_transform(from, to, up);
      THEN("it translate verything back by 8") {
        const Transform expected = Identity().translate(0, 0, -8);
        REQUIRE(ApproxEqual(view_transformation, expected));
      }
    }
  }
}
SCENARIO("An arbitrary view transformation") {
  GIVEN("a view transformation") {
    const Point from{1, 3, 2};
    const Point to{4, -2, 8};
    const Vector up{1, 1, 0};
    WHEN("the view transform is computed") {
      const auto view_transformation = view_transform(from, to, up);
      THEN("the values are correct") {
        const Transform expected{{{{-0.50709, 0.50709, 0.67612, -2.36643},
                                   {0.76772, 0.60609, 0.12122, -2.82843},
                                   {-0.35857, 0.59761, -0.71714, 0.00000},
                                   {0.00000, 0.00000, 0.00000, 1.00000}}}};
        REQUIRE(ApproxEqual(view_transformation, expected));
      }
    }
  }
}
}  // namespace ray_tracer
