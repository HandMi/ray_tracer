#include "writer/ppm_writer.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <sstream>

using namespace Catch;
using Catch::Matchers::Equals;

namespace ray_tracer {

SCENARIO("Write to PPM") {
  GIVEN("any canvas and a PPM Writer") {
    Canvas canvas{5, 3};
    writer::PPMWriter writer{};
    WHEN("the canvas is printed") {
      std::stringstream stream;
      writer.printCanvas(canvas, stream);
      THEN("the header is correctly written") {
        std::vector<std::string> result;
        while (!stream.eof()) {
          std::string line{};
          std::getline(stream, line);
          result.push_back(line);
        }
        REQUIRE(result.size() >= 2);

        REQUIRE_THAT(result[0], Equals("P3"));
      }
    }
    WHEN("colors are written") {
      canvas.set(0, 0, {1.5, 0., 0.});
      canvas.set(2, 1, {0., 0.5, 0.});
      canvas.set(4, 2, {-0.5, 0., 1.});
      AND_WHEN("the canvas is printed") {
        std::stringstream stream;
        writer.printCanvas(canvas, stream);
        THEN("the data is correct") {
          std::vector<std::string> result;
          while (!stream.eof()) {
            std::string line{};
            std::getline(stream, line);
            result.push_back(line);
          }
          REQUIRE(result.size() >= 6);

          REQUIRE_THAT(result[3], Equals("255 0 0 0 0 0 0 0 0 0 0 0 0 0 0"));
          REQUIRE_THAT(result[4], Equals("0 0 0 0 0 0 0 127 0 0 0 0 0 0 0"));
          REQUIRE_THAT(result[5], Equals("0 0 0 0 0 0 0 0 0 0 0 0 0 0 255"));
        }
      }
    }
    WHEN("every pixel is set") {
      canvas.setAll({1., 0.8, 0.6});
      AND_WHEN("the canvas is printed") {
        std::stringstream stream;
        writer.printCanvas(canvas, stream);
        THEN("no line is longer than 70 characters") {
          std::vector<std::string> result;
          while (!stream.eof()) {
            std::string line{};
            std::getline(stream, line);
            REQUIRE(line.size() < 70);
          }
        }
      }
    }
  }
}
}  // namespace ray_tracer