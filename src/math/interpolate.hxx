#ifndef CREATIVEXX_LERP_H
#define CREATIVEXX_LERP_H

#include <torch/torch.h>
#include <cstdint>

namespace creative {
namespace math {

template <typename VALUE_TYPE, typename AMOUNT_TYPE>
inline VALUE_TYPE linear_interpolate(VALUE_TYPE, VALUE_TYPE, AMOUNT_TYPE);

template <typename VALUE_TYPE, typename AMOUNT_TYPE>
inline VALUE_TYPE bilinear_interpolate(VALUE_TYPE,
                                       VALUE_TYPE,
                                       VALUE_TYPE,
                                       VALUE_TYPE,
                                       AMOUNT_TYPE,
                                       AMOUNT_TYPE);

template <typename VALUE_TYPE, typename AMOUNT_TYPE>
inline VALUE_TYPE trilinear_interpolate(VALUE_TYPE,
                                        VALUE_TYPE,
                                        VALUE_TYPE,
                                        VALUE_TYPE,
                                        VALUE_TYPE,
                                        VALUE_TYPE,
                                        VALUE_TYPE,
                                        VALUE_TYPE,
                                        AMOUNT_TYPE,
                                        AMOUNT_TYPE,
                                        AMOUNT_TYPE);

}  // namespace math
}  // namespace creative

#endif  // CREATIVEXX_LERP_H