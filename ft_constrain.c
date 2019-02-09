/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_constrain.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/02/09 12:37:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_constrain(long n, long num1, long num2)
{
	long	min;
	long	max;

	if (num1 < num2)
	{
		min = num1;
		max = num2;
	}
	else
	{
		min = num2;
		max = num1;
	}
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}
