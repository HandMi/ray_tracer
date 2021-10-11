#include "writer/ppm_writer.h"

namespace ray_tracer {
namespace writer {

namespace detail {
constexpr int clamp(Decimal x, const int lo, const int hi) {
  x *= static_cast<Decimal>(hi);
  return static_cast<int>(x) < lo
             ? lo
             : static_cast<int>(x) > hi ? hi : static_cast<int>(x);
}
}  // namespace detail

void PPMWriter::printHeader(const Canvas& canvas,
                            std::ostream& output_stream) const {
  output_stream << "P3"
                << "\n";
  output_stream << canvas.width << " " << canvas.height << "\n";
  output_stream << "255"
                << "\n";
};
void PPMWriter::printCanvas(const Canvas& canvas,
                            std::ostream& output_stream) const {
  printHeader(canvas, output_stream);
  int char_count{};
  for (UInteger j = 0U; j < canvas.height; ++j) {
    for (UInteger i = 0U; i < canvas.width; ++i) {
      auto color = canvas.get(i, j);
      auto r = detail::clamp(color.r(), 0, 255);
      auto g = detail::clamp(color.g(), 0, 255);
      auto b = detail::clamp(color.b(), 0, 255);
      output_stream << r << " " << g << " " << b;
      char_count += 12;
      if (char_count >= 60) {
        output_stream << "\n";
        char_count = 0;
      } else {
        output_stream << " ";
      }
    }
  }
  output_stream << "\n";
};
}  // namespace writer
}  // namespace ray_tracer