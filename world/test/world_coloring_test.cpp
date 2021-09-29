#include "core/utils.h"
#include "shapes/sphere.h"
#include "world/world.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("The color when a ray misses") {
  GIVEN("a world and a ray that misses") {
    auto world = world::World::Default();
    const Ray ray{{0., 0., -5.}, {0., 1., 0.}};
    WHEN("the color is computed") {
      const auto color = world.color_at(ray);
      THEN("the color is black") { REQUIRE(ApproxEqual(color, Colors::Black)); }
    }
  }
}
SCENARIO("The color when a ray hits") {
  GIVEN("a world and a ray that hits") {
    auto world = world::World::Default();
    const Ray ray{{0., 0., -5.}, {0., 0., 1.}};
    WHEN("the color is computed") {
      const auto color = world.color_at(ray);
      THEN("the color is correct") {
        REQUIRE(ApproxEqual(color, {0.38066, 0.47583, 0.2855}));
      }
    }
  }
}
SCENARIO("The color with an intersection behind the ray") {
  GIVEN("a world and a ray that hits inside") {
    auto mat1 = shapes::Material::create(Color{0.8, 1.0, 0.6});
    mat1->diffuse = 0.7;
    mat1->specular = 0.2;
    mat1->ambient = 1.0;
    auto mat2 = shapes::Material::create();
    mat2->ambient = 1.0;
    const auto transform = Identity().scale(0.5, 0.5, 0.5);

    const auto s1 = shapes::Sphere::create(Identity(), mat1);
    const auto s2 = shapes::Sphere::create(transform, mat2);
    const auto light = PointLight{{-10., 10., -10.}, {1., 1., 1.}};
    std::vector<PointLight> lights{light};

    world::World world(lights, {s1, s2});
    const Ray ray{{0., 0., 0.75}, {0., 0., -1.}};

    WHEN("the color is computed") {
      const auto color = world.color_at(ray);
      THEN("the color is correct") { REQUIRE(ApproxEqual(color, mat2->color)); }
    }
  }
}
}  // namespace ray_tracer
