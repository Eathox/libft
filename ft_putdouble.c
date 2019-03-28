/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:15:03 by pholster       #+#    #+#                */
/*   Updated: 2019/03/28 18:04:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdouble(long double value, size_t n)
{
	size_t		i;
	long long	num;
	long double	next;

	i = 0;
	num = (long long)value;
	ft_putnbr(num);
	if (n == 0)
		return ;
	ft_putchar('.');
	next = 0;
	value -= num;
	if (value < 0)
		value *= -1;
	while (i < n)
	{
		value *= 10;
		num = (long long)value;
		if (i + 1 == n)
			next = (value - num) * 10;
		ft_putnbr(value + (next >= 5));
		value -= num;
		i++;
	}
}
