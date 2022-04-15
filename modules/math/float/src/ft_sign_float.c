#include <math.h>
#include <stdbool.h>

#include "../include/float.h"
#include "types/include/types.h"

float128_t ft_sign_float(
    float128_t num
) {
    return copysignl(1, num);
}
