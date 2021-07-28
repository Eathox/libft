#include "types/include/types.h"
#include "float.h"

float128_t ft_overflow_float(
	float128_t value,
	float128_t min,
	float128_t max
) {
	if (value < min)
		return (ft_overflow_float(max + (value - min), min, max));
	if (value >= max)
		return (ft_overflow_float((value + min) - max, min, max));
	return (value);
}
