/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_abs_float.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/24 22:07:19 by pholster      #+#    #+#                 */
/*   Updated: 2021/06/24 22:07:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "float.h"

float128_t ft_abs_float(
	float128_t num
) {
	return (fabsl(num));
}
