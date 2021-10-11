#include "shapes/intersection.h"
#include "shapes/sphere.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("The hit, when all intersections have positive t") {
  GIVEN("two intersections") {
    const auto sphere = shapes::Sphere::create();
    shapes::Intersection i1{1., sphere};
    shapes::Intersection i2{2., sphere};
    WHEN("the intersection list is set up") {
      shapes::IntersectionList intersection_list;
      intersection_list.insert(i1);
      intersection_list.insert(i2);
      THEN("the hit is the lowest nonnegatiove value") {
        const auto hit = intersection_list.hit_candidate();
        REQUIRE(hit.has_value());
        REQUIRE(hit->t == 1.);
      }
    }
  }
}
SCENARIO("The hit, when some intersections have negative t") {
  GIVEN("two intersections") {
    const auto sphere = shapes::Sphere::create();
    shapes::Intersection i1{-1., sphere};
    shapes::Intersection i2{1., sphere};
    WHEN("the intersection list is set up") {
      shapes::IntersectionList intersection_list;
      intersection_list.insert(i1);
      intersection_list.insert(i2);
      THEN("the hit is the lowest nonnegatiove value") {
        const auto hit = intersection_list.hit_candidate();
        REQUIRE(hit.has_value());
        REQUIRE(hit->t == 1.);
      }
    }
  }
}
SCENARIO("The hit, when all intersections have negative t") {
  GIVEN("two intersections") {
    const auto sphere = shapes::Sphere::create();
    shapes::Intersection i1{-2., sphere};
    shapes::Intersection i2{-1., sphere};
    WHEN("the intersection list is set up") {
      shapes::IntersectionList intersection_list;
      intersection_list.insert(i1);
      intersection_list.insert(i2);
      THEN("the hit is the lowest nonnegatiove value") {
        const auto hit = intersection_list.hit_candidate();
        REQUIRE(hit.has_value()==false);
      }
    }
  }
}
SCENARIO("The hit is always the lowest nonnegative intersection") {
  GIVEN("four intersections") {
    const auto sphere = shapes::Sphere::create();
    shapes::Intersection i1{5., sphere};
    shapes::Intersection i2{7., sphere};
    shapes::Intersection i3{-3., sphere};
    shapes::Intersection i4{2., sphere};
    WHEN("the intersection list is set up") {
      shapes::IntersectionList intersection_list;
      intersection_list.insert(i1);
      intersection_list.insert(i2);
      intersection_list.insert(i3);
      intersection_list.insert(i4);
      THEN("the hit is the lowest nonnegatiove value") {
        const auto hit = intersection_list.hit_candidate();
        REQUIRE(hit.has_value());
        REQUIRE(hit->t == 2.);
      }
    }
  }
}
}  // namespace ray_tracer
