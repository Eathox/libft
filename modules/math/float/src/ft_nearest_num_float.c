#include <math.h>

#include "../include/float.h"
#include "types/include/types.h"

float128_t ft_nearest_num_float(
    float128_t value,
    float128_t num1,
    float128_t num2
) {
    float128_t const num1_distance = ft_abs_float(num1 - value);
    float128_t const num2_distance = ft_abs_float(num2 - value);

    if (num2_distance < num1_distance)
        return num2;
    return num1;
}