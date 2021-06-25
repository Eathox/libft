#pragma once

#include "../../types/types.h"

float128_t ft_abs_float(
	float128_t num
);

float128_t ft_max_float(
	float128_t num1,
	float128_t num2
);

float128_t ft_min_float(
	float128_t num1,
	float128_t num2
);

float128_t ft_clamp_float(
	float128_t value,
	float128_t min,
	float128_t max
);

float128_t ft_overflow_float(
	float128_t value,
	float128_t min,
	float128_t max
);

float128_t ft_normalize_float(
	float128_t value,
	float128_t const *range,
	float128_t const *outrange
);

float128_t ft_nearest_num_float(
	float128_t value,
	float128_t num1,
	float128_t num2
);

float128_t ft_sign_float(
	float128_t num
);
