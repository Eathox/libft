/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_overflow.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/23 14:12:31 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:17:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

float128_t ft_overflow(
	float128_t value,
	float128_t min,
	float128_t max
) {
	if (value < min)
		return (ft_overflow(max + (value - min), min, max));
	if (value >= max)
		return (ft_overflow((value + min) - max, min, max));
	return (value);
}
