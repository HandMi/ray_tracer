#include "camera/camera.h"
#include "common/types.h"
#include "core/canvas.h"
#include "core/view_transform.h"
#include "light/square_light.h"
#include "shapes/material.h"
#include "shapes/sphere.h"
#include "world/world.h"
#include "writer/ppm_writer.h"
#include <fstream>
#include <iostream>

int main() {
  using namespace ray_tracer;

  World world{};

  const auto floor_material = shapes::Material::create(Color{1, 0.9, 0.9});
  floor_material->specular = 0.;
  world.addShape<shapes::Sphere>(Identity().scale(10., 0.01, 10.),
                                 floor_material);

  world.addShape<shapes::Sphere>(Identity()
                                     .scale(10., 0.01, 10.)
                                     .rotate_x(PI / 2.)
                                     .rotate_y(-PI / 4.)
                                     .translate(0., 0., 5.),
                                 floor_material);

  world.addShape<shapes::Sphere>(Identity()
                                     .scale(10., 0.01, 10.)
                                     .rotate_x(PI / 2.)
                                     .rotate_y(PI / 4.)
                                     .translate(0., 0., 5.),
                                 floor_material);

  const auto right_material = shapes::Material::create(Color{0.5, 1, 0.1});
  right_material->diffuse = 0.7;
  right_material->specular = 0.3;
  world.addShape<shapes::Sphere>(
      Identity().scale(.5, .5, .5).translate(1.5, 0.5, -0.5), right_material);

  const auto middle_material = shapes::Material::create(Color{0.1, 1, 0.5});
  middle_material->diffuse = 0.7;
  middle_material->specular = 0.3;
  world.addShape<shapes::Sphere>(Identity().translate(-0.5, 1., 0.5),
                                 middle_material);

  const auto left_material = shapes::Material::create(Color{1, 0.8, 0.1});
  left_material->diffuse = 0.7;
  left_material->specular = 0.3;
  world.addShape<shapes::Sphere>(
      Identity().scale(.33, .33, .33).translate(-1.5, 0.33, -0.75),
      left_material);

  const Vector u{0.5, 0., 0.};
  const Vector v{0.5, 0., 0.};
  const UInteger u_steps{8};
  const UInteger v_steps{8};
  world.addLight<SquareLight>(Point(-10., 10., -10.), Color(1., 1., 1.), u,
                              u_steps, v, v_steps);

  Camera camera(1000, 500, PI / 3);
  camera.set_transform(view_transform(Point(0., 1.5, -5.), Point(0., 1., 0.),
                                      Vector(0., 1., 0.)));
  const auto canvas = camera.render(world);
  writer::PPMWriter writer{};
  std::ofstream file_stream;
  file_stream.open("soft_shadow_scene.ppm");
  writer.printCanvas(canvas, file_stream);
  file_stream.close();
  return 0;
}
