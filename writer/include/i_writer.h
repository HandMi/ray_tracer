#ifndef WRITER_I_WRITER_H
#define WRITER_I_WRITER_H

#include "canvas.h"
#include <iostream>

namespace ray_tracer {
namespace writer {

class IWriter {
 public:
  virtual void writeCanvasToFile(const Canvas& canvas,
                                 std::ostream& file_stream) const = 0;
  virtual ~IWriter() = 0;
};

}  // namespace writer
}  // namespace ray_tracer
#endif