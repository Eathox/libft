/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 23:47:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
