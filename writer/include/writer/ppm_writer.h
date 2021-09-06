#ifndef WRITER_PPM_WRITER_H
#define WRITER_PPM_WRITER_H

#include "i_writer.h"
#include <iostream>

namespace ray_tracer {
namespace writer {
class PPMWriter : public IWriter {
  void printHeader(const Canvas& canvas, std::ostream& output_stream) const;

 public:
  void printCanvas(const Canvas& canvas,
                   std::ostream& output_stream) const override;
};
}  // namespace writer
}  // namespace ray_tracer
#endif