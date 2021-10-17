#include "shapes/plane.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Intersect with a ray parallel to the plane") {
  GIVEN("a ray and a plane") {
    const Point origin{0, 10, 0};
    const Vector direction{0, 0, 1};
    const Ray ray{origin, direction};
    const auto plane = shapes::Plane::create();
    WHEN("the intersections are calculated") {
      const auto intersections = plane->intersect(ray);
      THEN("the list is empty") { REQUIRE(intersections.has_value() == false); }
    }
  }
}
SCENARIO("Intersect with a coplanar ray") {
  GIVEN("a ray and a plane") {
    const Point origin{0, 0, 0};
    const Vector direction{0, 0, 1};
    const Ray ray{origin, direction};
    const auto plane = shapes::Plane::create();
    WHEN("the intersections are calculated") {
      const auto intersections = plane->intersect(ray);
      THEN("the list is empty") { REQUIRE(intersections.has_value() == false); }
    }
  }
}
SCENARIO("A ray intersecting a plane from above") {
  GIVEN("a ray and a plane") {
    const Point origin{0, 1, 0};
    const Vector direction{0, -1, 0};
    const Ray ray{origin, direction};
    const auto plane = shapes::Plane::create();
    WHEN("the intersections are calculated") {
      const auto intersections = plane->intersect(ray);
      THEN("the values are correct.") { 
        REQUIRE(intersections->size() == 1);
        REQUIRE(intersections->at(0).t == Approx(1)); }
    }
  }
}
SCENARIO("A ray intersecting a plane from below") {
  GIVEN("a ray and a plane") {
    const Point origin{0, -1, 0};
    const Vector direction{0, 1, 0};
    const Ray ray{origin, direction};
    const auto plane = shapes::Plane::create();
    WHEN("the intersections are calculated") {
      const auto intersections = plane->intersect(ray);
      THEN("the values are correct.") { 
        REQUIRE(intersections->size() == 1);
        REQUIRE(intersections->at(0).t == Approx(1)); }
    }
  }
}
}  // namespace ray_tracer
