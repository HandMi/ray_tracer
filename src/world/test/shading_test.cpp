#include "light/point_light.h"
#include "shapes/sphere.h"
#include "utils/tuple_test_helper.h"
#include "world/world.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Shading an intersection") {
  GIVEN("a world and a ray") {
    auto world = World::Default();
    const Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    WHEN("the intersections and hits are computed") {
      auto intersection_list = world.intersect(ray);
      const auto hit =
          prepare_hit(intersection_list.hit_candidate().value(), ray);
      THEN("the shading is correct") {
        const auto color = world.shade(hit);
        REQUIRE(ApproxEqual(color, Color{0.38066, 0.47583, 0.2855}));
      }
    }
  }
}

SCENARIO("Shading an intersection from the inside") {
  GIVEN("a world and a ray") {
    auto mat = shapes::Material::create(Color{0.8, 1.0, 0.6});
    mat->diffuse = 0.7;
    mat->specular = 0.2;
    const auto transform = Identity().scale(0.5, 0.5, 0.5);

    World world{};
    world.addShape<shapes::Sphere>(Identity(), mat);
    world.addShape<shapes::Sphere>(transform);
    world.addLight<PointLight>(Point{0., 0.25, 0.}, Color{1., 1., 1.});

    const Ray ray{{0., 0., 0.}, {0., 0., 1.}};
    WHEN("the intersections and hits are computed") {
      auto intersection_list = world.intersect(ray);
      const auto hit =
          prepare_hit(intersection_list.hit_candidate().value(), ray);
      THEN("the shading is correct") {
        const auto color = world.shade(hit);
        REQUIRE(ApproxEqual(color, Color{0.90498, 0.90498, 0.90498}));
      }
    }
  }
}

SCENARIO("Shading an intersection in shadow") {
  GIVEN("a world and a ray") {
    const auto transform = Identity().translate(0, 0, 10);

    World world{};
    const auto s2 = shapes::Sphere::create(transform);
    world.addShape<shapes::Sphere>();
    world.addShape<shapes::Sphere>(transform);
    world.addLight<PointLight>(Point{0., 0., -10.}, Color{1., 1., 1.});

    const Ray ray{{0., 0., 5.}, {0., 0., 1.}};
    WHEN("the intersections and hits are computed") {
      const auto intersect = shapes::Intersection{4., s2};
      const auto hit = prepare_hit(intersect, ray);
      THEN("the shading is correct") {
        const auto color = world.shade(hit);
        REQUIRE(ApproxEqual(color, Color{0.1, 0.1, 0.1}));
      }
    }
  }
}
}  // namespace ray_tracer
