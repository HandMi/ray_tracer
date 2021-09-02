#ifndef WRITER_PPM_WRITER_H
#define WRITER_PPM_WRITER_H

#include "i_writer.h"
#include <iostream>

namespace ray_tracer {
namespace writer {
class PPMWriter : IWriter {
  void write_header( const Canvas& canvas, std::ostream& file_stream) const;

 public:
  void writeCanvasToFile(const Canvas& canvas,
                         std::ostream& file_stream) const override;
};
}  // namespace writer
}  // namespace ray_tracer
#endif