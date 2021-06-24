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

t_float128 ft_overflow(
	t_float128 value,
	t_float128 min,
	t_float128 max
) {
	if (value < min)
		return (ft_overflow(max + (value - min), min, max));
	if (value >= max)
		return (ft_overflow((value + min) - max, min, max));
	return (value);
}
