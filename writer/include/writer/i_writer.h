#ifndef WRITER_I_WRITER_H
#define WRITER_I_WRITER_H

#include "core/canvas.h"
#include <iostream>

namespace ray_tracer {
namespace writer {

class IWriter {
 public:
  virtual ~IWriter(){};
  virtual void printCanvas(const Canvas& canvas,
                           std::ostream& output_stream) const = 0;
};

}  // namespace writer
}  // namespace ray_tracer
#endif