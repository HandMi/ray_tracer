#include "core/color.h"
#include "patterns/stripe.h"
#include "utils/tuple_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Stripe pattern coloration") {
  const auto black = Colors::Black;
  const auto white = Colors::White;
  const auto stripe_pattern = patterns::Stripe::create(white, black);
  GIVEN("a stripe pattern") {
    THEN("it is constant in y") {
      REQUIRE(ApproxEqual(stripe_pattern->at(Point(0., 0., 0.)), white));
      REQUIRE(ApproxEqual(stripe_pattern->at(Point(0., 1., 0.)), white));
      REQUIRE(ApproxEqual(stripe_pattern->at(Point(0., 2., 0.)), white));
    }
  }
}
}  // namespace ray_tracer
