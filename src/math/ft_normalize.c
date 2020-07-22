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

#include "math.h"

long double	ft_normalize(
	long double value,
	long double const *range,
	long double const *outrange
)
{
	long double const	range_min = range[0];
	long double const	range_max = range[1];
	long double const	outrange_min = outrange[0];
	long double const	outrange_max = outrange[1];
	long double			out;

	out = (outrange_max - outrange_min) / (range_max - range_min);
	out *= outrange_min + (value - range_min);
	return (out);
}
