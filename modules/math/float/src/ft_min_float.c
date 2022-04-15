#include <math.h>

#include "types/include/types.h"
#include "float.h"

float128_t ft_min_float(
	float128_t num1,
	float128_t num2
) {
	return (fminl(num1, num2));
}
