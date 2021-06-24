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

float128_t ft_normalize(
	float128_t value,
	float128_t const *range,
	float128_t const *outrange
) {
	float128_t const range_min = range[0];
	float128_t const range_max = range[1];
	float128_t const outrange_min = outrange[0];
	float128_t const outrange_max = outrange[1];

	float128_t out = (outrange_max - outrange_min) / (range_max - range_min);
	out *= outrange_min + (value - range_min);
	return (out);
}
