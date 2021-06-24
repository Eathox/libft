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

t_float128 ft_max(
	t_float128 num1,
	t_float128 num2
);

t_float128 ft_min(
	t_float128 num1,
	t_float128 num2
);

t_float128 ft_clamp(
	t_float128 value,
	t_float128 min,
	t_float128 max
);

t_float128 ft_overflow(
	t_float128 value,
	t_float128 min,
	t_float128 max
);

t_float128 ft_normalize(
	t_float128 value,
	t_float128 const *range,
	t_float128 const *outrange
);

t_float128 ft_nearestnum(
	t_float128 value,
	t_float128 num1,
	t_float128 num2
);

t_float128 ft_sign(
	t_float128 num
);
