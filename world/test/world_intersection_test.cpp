#include "world/world.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Intersect a world with a ray") {
  GIVEN("a world and a ray") {
    auto world = world::World::Default();
    const Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    WHEN("the intersections are computed") {
      const auto intersection_list = world.intersect(ray);
      THEN("the intersection list is sorted") {
        REQUIRE(intersection_list.count()== 4);
        REQUIRE(intersection_list[0].t == Approx(4.));
        REQUIRE(intersection_list[1].t == Approx(4.5));
        REQUIRE(intersection_list[2].t == Approx(5.5));
        REQUIRE(intersection_list[3].t == Approx(6.));
      }
    }
  }
}
}  // namespace ray_tracer
