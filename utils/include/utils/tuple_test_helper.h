
#ifndef UTILS_INCLUDE_TUPLE_TEST_HELPER_H
#define UTILS_INCLUDE_TUPLE_TEST_HELPER_H

#include "core/tuple.h"
#include <cmath>
#include <iostream>

namespace ray_tracer {

template <class TupleType>
bool ApproxEqual(const TupleType& tuple1,
                 const TupleType& tuple2,
                 const Decimal epsilon = 0.0001) {
  for (UInteger i = 0; i < TupleType::size; ++i) {
      if (std::abs(tuple1(i) - tuple2(i)) > epsilon) {
        std::cout << "Mismatch at index " << i << "\n";
        return false;
      }
  }
  return true;
}


}  // namespace ray_tracer

#endif
