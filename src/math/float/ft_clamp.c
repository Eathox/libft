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

long double	ft_clamp(
	long double value,
	long double max,
	long double min
) {
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
