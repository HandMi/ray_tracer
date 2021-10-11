#include "light/ray.h"
#include "shapes/intersection.h"
#include "shapes/sphere.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Intersecting a scaled sphere with a ray") {
  GIVEN("a scaled sphere and a ray") {
    const Transform transform = Identity().scale(2., 2., 2.);
    const auto sphere = shapes::Sphere::create(transform);
    Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    WHEN("the intersection is computed") {
      const auto intersect = sphere->intersect(ray);
      THEN("the values are correct") {
        REQUIRE(intersect.has_value());
        REQUIRE(intersect->at(0).t == Approx(3.));
        REQUIRE(intersect->at(1).t == Approx(7.));
      }
    }
  }
}
SCENARIO("Intersecting a translated sphere with a ray") {
  GIVEN("a translated sphere and a ray") {
    const Transform transform = Identity().translate(5., 0., 0.);
    const auto sphere = shapes::Sphere::create(transform);
    Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    WHEN("the intersection is computed") {
      const auto intersect = sphere->intersect(ray);
      THEN("the values are correct") {
        REQUIRE(intersect.has_value() == false);
      }
    }
  }
}
}  // namespace ray_tracer
