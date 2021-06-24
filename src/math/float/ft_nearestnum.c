/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nearestnum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:56:32 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:41:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "float.h"

t_float128 ft_nearestnum(
	t_float128 value,
	t_float128 num1,
	t_float128 num2
) {
	long double const num1_distance = fabsl(num1 - value);
	long double const num2_distance = fabsl(num2 - value);

	if (num2_distance < num1_distance)
		return (num2);
	return (num1);
}
