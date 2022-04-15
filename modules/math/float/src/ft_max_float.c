#include <math.h>

#include "types/include/types.h"
#include "float.h"

float128_t ft_max_float(
	float128_t num1,
	float128_t num2
) {
	return (fmaxl(num1, num2));
}
