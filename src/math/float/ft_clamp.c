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

float128_t ft_clamp(
	float128_t value,
	float128_t min,
	float128_t max
) {
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
