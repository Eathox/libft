/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:40:13 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:15:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

t_float128 ft_min(
	t_float128 num1,
	t_float128 num2
) {
	if (num1 < num2)
		return (num1);
	return (num2);
}
