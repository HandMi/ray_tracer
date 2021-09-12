#ifndef CORE_INCLUDE_TRANSFORMATIONS_H
#define CORE_INCLUDE_TRANSFORMATIONS_H

#include "utils/constants.h"
#include <array>
#include <cmath>

namespace ray_tracer {
template <class DerivedType, class MatrixType>
struct Transformations {
  constexpr DerivedType& translate(Decimal x, Decimal y, Decimal z) {
    auto ptr_to_derived = static_cast<DerivedType*>(this);
    MatrixType translation_matrix{{{{1., 0., 0., x},
                                    {0., 1., 0., y},
                                    {0., 0., 1., z},
                                    {0., 0., 0., 1.}}}};
    *ptr_to_derived = translation_matrix * (*ptr_to_derived);
    return static_cast<DerivedType&>(*ptr_to_derived);
  }
  constexpr DerivedType& scale(Decimal x, Decimal y, Decimal z) {
    auto ptr_to_derived = static_cast<DerivedType*>(this);
    MatrixType scaling_matrix{{{{x, 0., 0., 0.},
                                {0., y, 0., 0.},
                                {0., 0., z, 0.},
                                {0., 0., 0., 1.}}}};
    *ptr_to_derived = scaling_matrix * (*ptr_to_derived);
    return static_cast<DerivedType&>(*ptr_to_derived);
  }
  constexpr DerivedType& rotate_x(Decimal phi) {
    auto ptr_to_derived = static_cast<DerivedType*>(this);
    MatrixType rotation_matrix{{{{1., 0., 0., 0.},
                                 {0., std::cos(phi), -std::sin(phi), 0.},
                                 {0., std::sin(phi), std::cos(phi), 0.},
                                 {0., 0., 0., 1.}}}};
    *ptr_to_derived = rotation_matrix * (*ptr_to_derived);
    return static_cast<DerivedType&>(*ptr_to_derived);
  }
  constexpr DerivedType& rotate_y(Decimal phi) {
    auto ptr_to_derived = static_cast<DerivedType*>(this);
    MatrixType rotation_matrix{{{{std::cos(phi), 0., std::sin(phi), 0.},
                                 {0., 1., 0., 0.},
                                 {-std::sin(phi), 0., std::cos(phi), 0.},
                                 {0., 0., 0., 1.}}}};
    *ptr_to_derived = rotation_matrix * (*ptr_to_derived);
    return static_cast<DerivedType&>(*ptr_to_derived);
  }
  constexpr DerivedType& rotate_z(Decimal phi) {
    auto ptr_to_derived = static_cast<DerivedType*>(this);
    MatrixType rotation_matrix{{{{std::cos(phi), -std::sin(phi), 0., 0.},
                                 {std::sin(phi), std::cos(phi), 0., 0.},
                                 {0., 0., 1., 0.},
                                 {0., 0., 0., 1.}}}};
    *ptr_to_derived = rotation_matrix * (*ptr_to_derived);
    return static_cast<DerivedType&>(*ptr_to_derived);
  }
  constexpr DerivedType& shear(Decimal xy, Decimal xz, Decimal yx, Decimal yz,
                               Decimal zx, Decimal zy) {
    auto ptr_to_derived = static_cast<DerivedType*>(this);
    MatrixType shearing_matrix{{{{1., xy, xz, 0.},
                                 {yx, 1., yz, 0.},
                                 {zx, zy, 1., 0.},
                                 {0., 0., 0., 1.}}}};
    *ptr_to_derived = shearing_matrix * (*ptr_to_derived);
    return static_cast<DerivedType&>(*ptr_to_derived);
  }
};
}  // namespace ray_tracer
#endif