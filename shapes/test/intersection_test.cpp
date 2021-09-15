#include "shapes/sphere.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("A ray intersects a sphere at two points") {
  GIVEN("a ray and a sphere") {
    const Point origin{0, 0, -5};
    const Vector direction{0, 0, 1};
    const Ray ray{origin, direction};
    const auto sphere = shapes::Sphere::create();
    WHEN("the intersections are calculated") {
      const auto intersections = sphere->intersect(ray);
      THEN("the values are correct") {
        REQUIRE(intersections->size() == 2);
        REQUIRE(intersections->at(0).t == Approx(4.0));
        REQUIRE(intersections->at(1).t == Approx(6.0));
      }
    }
  }
}
SCENARIO("A ray intersects a sphere at a tangent") {
  GIVEN("a ray and a sphere") {
    const Point origin{0, 1, -5};
    const Vector direction{0, 0, 1};
    const Ray ray{origin, direction};
    const auto sphere = shapes::Sphere::create();
    WHEN("the intersections are calculated") {
      const auto intersections = sphere->intersect(ray);
      THEN("the values are correct") {
        REQUIRE(intersections->size() == 2);
        REQUIRE(intersections->at(0).t == Approx(5.0));
        REQUIRE(intersections->at(1).t == Approx(5.0));
      }
    }
  }
}
SCENARIO("A ray misses a sphere") {
  GIVEN("a ray and a sphere") {
    const Point origin{0, 2, -5};
    const Vector direction{0, 0, 1};
    const Ray ray{origin, direction};
    const auto sphere = shapes::Sphere::create();
    WHEN("the intersections are calculated") {
      const auto intersections = sphere->intersect(ray);
      THEN("the values are correct") {
        REQUIRE(intersections.has_value() == false);
      }
    }
  }
}
SCENARIO("A ray originates inside a sphere") {
  GIVEN("a ray and a sphere") {
    const Point origin{0, 0, 0};
    const Vector direction{0, 0, 1};
    const Ray ray{origin, direction};
    const auto sphere = shapes::Sphere::create();
    WHEN("the intersections are calculated") {
      const auto intersections = sphere->intersect(ray);
      THEN("the values are correct") {
        REQUIRE(intersections->size() == 2);
        REQUIRE(intersections->at(0).t == Approx(-1.0));
        REQUIRE(intersections->at(1).t == Approx(1.0));
      }
    }
  }
}
SCENARIO("A sphere is behind a ray") {
  GIVEN("a ray and a sphere") {
    const Point origin{0, 0, 5};
    const Vector direction{0, 0, 1};
    const Ray ray{origin, direction};
    const auto sphere = shapes::Sphere::create();
    WHEN("the intersections are calculated") {
      const auto intersections = sphere->intersect(ray);
      THEN("the values are correct") {
        REQUIRE(intersections->size() == 2);
        REQUIRE(intersections->at(0).t == Approx(-6.0));
        REQUIRE(intersections->at(1).t == Approx(-4.0));
      }
    }
  }
}
}  // namespace ray_tracer
