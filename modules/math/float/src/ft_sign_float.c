#include <math.h>

#include "float.h"

float128_t ft_sign_float(
	float128_t num
) {
	if (num == INFINITY)
		return (INFINITY);
	else if (num > 0.0)
		return (1.0);
	else if (num < 0.0)
		return (-1.0);
	return (num);
}
