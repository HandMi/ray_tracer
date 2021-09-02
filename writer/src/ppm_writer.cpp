#include "ppm_writer.h"

namespace ray_tracer {
namespace writer {

namespace detail {
constexpr int clamp(Decimal x, const int lo, const int hi) {
  x *= static_cast<Decimal>(hi);
  return static_cast<int>(x) < lo ? lo : static_cast<int>(x) > hi ? hi : static_cast<int>(x);
}
}  // namespace detail

void PPMWriter::write_header(const Canvas& canvas,
                             std::ostream& file_stream) const {
  file_stream << "P3"
              << "\n";
  file_stream << canvas.width << " " << canvas.height << "\n";
  file_stream << "255"
              << "\n";
};
void PPMWriter::writeCanvasToFile(const Canvas& canvas,
                                  std::ostream& file_stream) const {
  write_header(canvas, file_stream);
  for (std::size_t i = 0U; i < canvas.height; ++i) {
    for (std::size_t j = 0U; j < canvas.height; ++j) {
      auto color = canvas.get(i, j);
      auto r = detail::clamp(color.r, 0, 255);
      auto g = detail::clamp(color.g, 0, 255);
      auto b = detail::clamp(color.b, 0, 255);
      file_stream << r << " " << g << " " << b << " ";
    }
    file_stream << "\n";
  }
};
}  // namespace writer
}  // namespace ray_tracer