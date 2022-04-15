#include "../include/float.h"
#include "types/include/types.h"

float128_t ft_normalize_float(
    float128_t value,
    float128_t const *range,
    float128_t const *outrange
) {
    float128_t const range_min = range[0];
    float128_t const range_max = range[1];
    float128_t const outrange_min = outrange[0];
    float128_t const outrange_max = outrange[1];

    float128_t out = (outrange_max - outrange_min) / (range_max - range_min);
    out *= outrange_min + (value - range_min);
    return out;
}
