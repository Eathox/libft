/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clamp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 13:40:29 by pholster      #+#    #+#                 */
/*   Updated: 2020/06/02 13:40:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

t_float128 ft_clamp(
	t_float128 value,
	t_float128 min,
	t_float128 max
) {
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
