#include "types/include/types.h"
#include "float.h"

float128_t ft_max_float(
	float128_t num1,
	float128_t num2
) {
	if (num1 > num2)
		return (num1);
	return (num2);
}
