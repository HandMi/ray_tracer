#include "light/point_light.h"
#include "shapes/material.h"
#include "utils/tuple_test_helper.h"
#include <catch2/catch_approx.hpp>
#include <catch2/catch_test_macros.hpp>

using namespace Catch;

namespace ray_tracer {

SCENARIO("Lighting with the eye between the light and the surface") {
  GIVEN("Given a default material and and eye position") {
    const auto material = shapes::Material::create();
    const PointLight point_light{Point{0., 0., -10.}, Color{1., 1., 1.}};
    const Point position{0., 0., 0.};
    const Vector eye_vector{0., 0., -1.};
    const Vector normal{0., 0., -1.};
    WHEN("the intensity is computed") {
      const auto intensity =
          point_light.lighting(material, position, eye_vector, normal);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(intensity, Color{1.9, 1.9, 1.9}));
      }
    }
  }
}
SCENARIO("Lighting with the surface in shadow") {
  GIVEN("Given a default material and and eye position") {
    const auto material = shapes::Material::create();
    const PointLight point_light{Point{0., 0., -10.}, Color{1., 1., 1.}};
    const Point position{0., 0., 0.};
    const Vector eye_vector{0., 0., -1.};
    const Vector normal{0., 0., -1.};
    WHEN("the intensity is computed") {
      const auto intensity =
          point_light.lighting(material, position, eye_vector, normal, 0.);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(intensity, Color{0.1, 0.1, 0.1}));
      }
    }
  }
}
SCENARIO("Lighting with the eye between light and surface, eye offset 45°") {
  GIVEN("Given a default material and and eye position") {
    const auto material = shapes::Material::create();
    const PointLight point_light{Point{0., 0., -10.}, Color{1., 1., 1.}};
    const Point position{0., 0., 0.};
    const Vector eye_vector{0., std::sqrt(2.) / 2., -std::sqrt(2.) / 2.};
    const Vector normal{0., 0., -1.};
    WHEN("the intensity is computed") {
      const auto intensity =
          point_light.lighting(material, position, eye_vector, normal);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(intensity, Color{1.0, 1.0, 1.0}));
      }
    }
  }
}
SCENARIO("Lighting with eye opposite surface, light offset 45°") {
  GIVEN("Given a default material and and eye position") {
    const auto material = shapes::Material::create();
    const PointLight point_light{Point{0., 10., -10.}, Color{1., 1., 1.}};
    const Point position{0., 0., 0.};
    const Vector eye_vector{0., 0., -1.};
    const Vector normal{0., 0., -1.};
    WHEN("the intensity is computed") {
      const auto intensity =
          point_light.lighting(material, position, eye_vector, normal);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(intensity, Color{0.7364, 0.7364, 0.7364}));
      }
    }
  }
}
SCENARIO("Lighting with eye in the path of the reflection vector") {
  GIVEN("Given a default material and and eye position") {
    const auto material = shapes::Material::create();
    const PointLight point_light{Point{0., 10., -10.}, Color{1., 1., 1.}};
    const Point position{0., 0., 0.};
    const Vector eye_vector{0., -std::sqrt(2.) / 2., -std::sqrt(2.) / 2.};
    const Vector normal{0., 0., -1.};
    WHEN("the intensity is computed") {
      const auto intensity =
          point_light.lighting(material, position, eye_vector, normal);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(intensity, Color{1.6364, 1.6364, 1.6364}));
      }
    }
  }
}
SCENARIO("Lighting uses light intensity to attenuate color") {
  GIVEN("Given a  material and and eye position") {
    auto material = shapes::Material::create();
    material->ambient = .1;
    material->diffuse = .9;
    material->specular = 0.;
    const PointLight point_light{Point{0., 0., -10.}, Color{1., 1., 1.}};
    const Point position{0., 0., -1};
    const Vector eye_vector{0., 0., -1.};
    const Vector normal{0., 0., -1.};
    WHEN("the color intensity is computed with less light intensity") {
      const auto intensity =
          point_light.lighting(material, position, eye_vector, normal, .5);
      THEN("the values are correct") {
        REQUIRE(ApproxEqual(intensity, Color{0.55, 0.55, 0.55}));
      }
    }
  }
}
}  // namespace ray_tracer
