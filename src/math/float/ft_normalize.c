/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_normalize.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:15:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

t_float128 ft_normalize(
	t_float128 value,
	t_float128 const *range,
	t_float128 const *outrange
) {
	t_float128 const range_min = range[0];
	t_float128 const range_max = range[1];
	t_float128 const outrange_min = outrange[0];
	t_float128 const outrange_max = outrange[1];

	t_float128 out = (outrange_max - outrange_min) / (range_max - range_min);
	out *= outrange_min + (value - range_min);
	return (out);
}
