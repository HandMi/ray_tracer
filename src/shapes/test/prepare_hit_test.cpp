#include "core/transform.h"
#include "shapes/intersection.h"
#include "shapes/sphere.h"
#include "utils/tuple_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Precomputing the state of an intersection") {
  GIVEN("a ray, a sphere and an intersection") {
    Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    const auto sphere = shapes::Sphere::create();
    shapes::Intersection intersect{4., sphere};
    WHEN("the hit is prepared") {
      const auto hit = prepare_hit(intersect, ray);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(hit.point, Point{0., 0., -1.}));
        REQUIRE(ApproxEqual(hit.eye_vector, Vector{0., 0., -1.}));
        REQUIRE(ApproxEqual(hit.normal, Vector{0., 0., -1.}));
      }
    }
  }
}

SCENARIO("The hit, when an intersection occurs on the outside") {
  GIVEN("a ray, a sphere and an intersection") {
    Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    const auto sphere = shapes::Sphere::create();
    shapes::Intersection intersect{4., sphere};
    WHEN("the hit is prepared") {
      const auto hit = prepare_hit(intersect, ray);
      THEN("the values are correct") { REQUIRE(hit.inside == false); }
    }
  }
}

SCENARIO("The hit, when an intersection occurs on the inside") {
  GIVEN("a ray, a sphere and an intersection") {
    Ray ray{{0., 0., 0.}, {0., 0., 1.}};
    const auto sphere = shapes::Sphere::create();
    shapes::Intersection intersect{1., sphere};
    WHEN("the hit is prepared") {
      const auto hit = prepare_hit(intersect, ray);
      THEN("the values are correct") { REQUIRE(hit.inside == true); }
    }
  }
}

SCENARIO("The hit should offset the point") {
  GIVEN("a ray, a sphere and an intersection") {
    Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    const auto transform = Identity().translate(0., 0., 1.);
    const auto sphere = shapes::Sphere::create(transform);
    shapes::Intersection intersect{5., sphere};
    WHEN("the hit is prepared") {
      const auto hit = prepare_hit(intersect, ray);
      THEN("the offset point is on the correct side") {
        REQUIRE(hit.over_point.z() < -EPSILON / 2.);
        REQUIRE(hit.point.z() > hit.over_point.z());
      }
    }
  }
}

}  // namespace ray_tracer
