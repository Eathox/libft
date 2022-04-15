#include "../include/float.h"
#include "types/include/types.h"

float128_t ft_clamp_float(
    float128_t value,
    float128_t min,
    float128_t max
) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}
