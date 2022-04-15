#include <stdbool.h>
#include <math.h>

#include "types/include/types.h"
#include "../include/float.h"

float128_t ft_sign_float(
	float128_t num
) {
	return (copysignl(1, num));
}
