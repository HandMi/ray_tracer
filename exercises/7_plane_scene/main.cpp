#include "camera/camera.h"
#include "core/canvas.h"
#include "core/view_transform.h"
#include "light/point_light.h"
#include "shapes/material.h"
#include "shapes/plane.h"
#include "shapes/sphere.h"
#include "world/world.h"
#include "writer/ppm_writer.h"
#include <fstream>
#include <iostream>

int main() {
  using namespace ray_tracer;

  World world{};

  const auto floor_material = shapes::Material::create(Color{1, 0.9, 0.9});
  world.addShape<shapes::Plane>(Identity(), floor_material);
  world.addShape<shapes::Plane>(
      Identity().rotate_x(PI / 2.).rotate_y(PI / 4.).translate(0., 0., 10.), floor_material);
  world.addShape<shapes::Plane>(
      Identity().rotate_x(PI / 2.).rotate_y(-PI / 4.).translate(0., 0., 10.), floor_material);

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

  world.addLight<PointLight>(Point(-10., 10., -10.), Color(0.5, 0.5, 0.5));
  world.addLight<PointLight>(Point(5., 10., -10.), Color(0.4, 0.4, 0.4));

  Camera camera(1000, 500, PI / 3);
  camera.set_transform(view_transform(Point(0., 1.5, -5.), Point(0., 1., 0.),
                                      Vector(0., 1., 0.)));
  const auto canvas = camera.render(world);
  writer::PPMWriter writer{};
  std::ofstream file_stream;
  file_stream.open("plane_scene.ppm");
  writer.printCanvas(canvas, file_stream);
  file_stream.close();
  return 0;
}
