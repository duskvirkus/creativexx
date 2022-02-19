#ifndef CREATIVEXX_LERP_H
#define CREATIVEXX_LERP_H

#include <torch/torch.h>
#include <cstdint>

namespace creative {
namespace math {

// template <typename VALUE_TYPE, typename AMOUNT_TYPE>
// VALUE_TYPE linear_interpolate(VALUE_TYPE, VALUE_TYPE, AMOUNT_TYPE);

// template <typename VALUE_TYPE, typename AMOUNT_TYPE>
// VALUE_TYPE bilinear_interpolate(VALUE_TYPE,
//                                 VALUE_TYPE,
//                                 VALUE_TYPE,
//                                 VALUE_TYPE,
//                                 AMOUNT_TYPE,
//                                 AMOUNT_TYPE);

// template <typename VALUE_TYPE, typename AMOUNT_TYPE>
// VALUE_TYPE trilinear_interpolate(VALUE_TYPE,
//                                  VALUE_TYPE,
//                                  VALUE_TYPE,
//                                  VALUE_TYPE,
//                                  VALUE_TYPE,
//                                  VALUE_TYPE,
//                                  VALUE_TYPE,
//                                  VALUE_TYPE,
//                                  AMOUNT_TYPE,
//                                  AMOUNT_TYPE,
//                                  AMOUNT_TYPE);

template <typename VALUE_TYPE, typename AMOUNT_TYPE>
inline VALUE_TYPE linear_interpolate(VALUE_TYPE start,
                                     VALUE_TYPE stop,
                                     AMOUNT_TYPE amount) {
  return amount * (stop - start) + start;
}

template <typename VALUE_TYPE, typename AMOUNT_TYPE>
inline VALUE_TYPE bilinear_interpolate(VALUE_TYPE value1,
                                       VALUE_TYPE value2,
                                       VALUE_TYPE value3,
                                       VALUE_TYPE value4,
                                       AMOUNT_TYPE amount1,
                                       AMOUNT_TYPE amount2) {
  VALUE_TYPE s =
      linear_interpolate<VALUE_TYPE, AMOUNT_TYPE>(value1, value2, amount1);
  VALUE_TYPE t =
      linear_interpolate<VALUE_TYPE, AMOUNT_TYPE>(value3, value4, amount1);
  return linear_interpolate<VALUE_TYPE, AMOUNT_TYPE>(s, t, amount2);
}

template <typename VALUE_TYPE, typename AMOUNT_TYPE>
inline VALUE_TYPE trilinear_interpolate(VALUE_TYPE value1,
                                        VALUE_TYPE value2,
                                        VALUE_TYPE value3,
                                        VALUE_TYPE value4,
                                        VALUE_TYPE value5,
                                        VALUE_TYPE value6,
                                        VALUE_TYPE value7,
                                        VALUE_TYPE value8,
                                        AMOUNT_TYPE amount1,
                                        AMOUNT_TYPE amount2,
                                        AMOUNT_TYPE amount3) {
  VALUE_TYPE s = bilinear_interpolate<VALUE_TYPE, AMOUNT_TYPE>(
      value1, value2, value3, value4, amount1, amount2);
  VALUE_TYPE t = bilinear_interpolate<VALUE_TYPE, AMOUNT_TYPE>(
      value5, value6, value7, value8, amount1, amount2);
  return linear_interpolate<VALUE_TYPE, AMOUNT_TYPE>(s, t, amount3);
}

}  // namespace math
}  // namespace creative

#endif  // CREATIVEXX_LERP_H