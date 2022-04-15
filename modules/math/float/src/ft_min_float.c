#include <math.h>

#include "../include/float.h"
#include "types/include/types.h"

float128_t ft_min_float(
    float128_t num1,
    float128_t num2
) {
    return fminl(num1, num2);
}
