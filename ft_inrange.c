/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_inrange.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/06/27 17:02:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_inrange(long long value, long long num1, long long num2)
{
	long long	min;
	long long	max;

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
	if (value < min || value > max)
		return (FALSE);
	return (TRUE);
}
