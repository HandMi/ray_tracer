#include "core/utils.h"
#include "shapes/sphere.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("The normal on a sphere at a point on the x axis") {
  GIVEN("a unit sphere") {
    const auto sphere = shapes::Sphere::create();
    WHEN("the normal is computed") {
      const auto normal = sphere->normal_at({1, 0, 0});
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(normal, Vector{1, 0, 0}));
      }
    }
  }
}
SCENARIO("The normal on a sphere at a point on the y axis") {
  GIVEN("a unit sphere") {
    const auto sphere = shapes::Sphere::create();
    WHEN("the normal is computed") {
      const auto normal = sphere->normal_at({0, 1, 0});
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(normal, Vector{0, 1, 0}));
      }
    }
  }
}
SCENARIO("The normal on a sphere at a point on the z axis") {
  GIVEN("a unit sphere") {
    const auto sphere = shapes::Sphere::create();
    WHEN("the normal is computed") {
      const auto normal = sphere->normal_at({0, 0, 1});
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(normal, Vector{0, 0, 1}));
      }
    }
  }
}
SCENARIO("The normal on a sphere at a nonaxial point") {
  GIVEN("a unit sphere") {
    const auto sphere = shapes::Sphere::create();
    WHEN("the normal is computed") {
      const auto normal = sphere->normal_at(
          {std::sqrt(3) / 3, std::sqrt(3) / 3, std::sqrt(3) / 3});
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(normal, Vector{std::sqrt(3) / 3, std::sqrt(3) / 3,
                                           std::sqrt(3) / 3}));
      }
    }
  }
}
SCENARIO("Computing the normal on a translated sphere") {
  GIVEN("a translated unit sphere") {
    const auto sphere = shapes::Sphere::create();
    const Transform transform = Identity().translate(0., 1., 0.);
    sphere->set_transform(transform);
    WHEN("the normal is computed") {
      const auto normal = sphere->normal_at({0, 1.70711, -0.70711});
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(normal, Vector{0, 0.70711, -0.70711}));
      }
    }
  }
}
SCENARIO("Computing the normal on a transformed sphere") {
  GIVEN("a scaled and rotated unit sphere") {
    const auto sphere = shapes::Sphere::create();
    const Transform transform =
        Identity().rotate_z(PI / 5).scale(1., 0.5, 1.);
    sphere->set_transform(transform);
    WHEN("the normal is computed") {
      const auto normal =
          sphere->normal_at({0, std::sqrt(2) / 2, -std::sqrt(2) / 2});
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(normal, Vector{0, 0.97014, -0.24254}));
      }
    }
  }
}
}  // namespace ray_tracer
