/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nearestnum.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 12:56:32 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

intmax_t	ft_nearestnum(intmax_t value, intmax_t num1, intmax_t num2)
{
	intmax_t num1distance;
	intmax_t num2distance;

	num1distance = ft_abs(num1) - ft_abs(value);
	num2distance = ft_abs(num2) - ft_abs(value);
	if (num2distance < num1distance)
		return (num2);
	return (num1);
}