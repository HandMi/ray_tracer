
#include "light/square_light.h"
#include "shapes/material.h"
#include "world/world.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Lighting samples the area light") {
  GIVEN("a material and a Square Light") {
    const Point light_position{-0.5, -0.5, -5.};
    const Vector v1{1., 0., 0.};
    const Vector v2{0., 1., 0.};
    const SquareLight light{light_position, Color{1., 1., 1.}, v1, 2, v2, 2};
    auto material = shapes::Material::create(Color{1., 1., 1.});
    material->ambient = .1, material->diffuse = .9;
    const Point eye{0., 0., -5};
    const Point pt{};
    auto eye_v = eye - pt;
    eye_v.normalize();
    const Vector normal_v{pt.x(), pt.y(), pt.z()};

    WHEN("the intensity at a point in the light is calculated") {
      const auto color = light.lighting(material, pt, eye_v, normal_v, 1.);
      THEN("the value is less than 1.") {
        REQUIRE(color.r() < 1.0 - EPSILON);
        REQUIRE(color.g() < 1.0 - EPSILON);
        REQUIRE(color.b() < 1.0 - EPSILON);
      }
    }
  }
}
}  // namespace ray_tracer
