/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:15:03 by pholster       #+#    #+#                */
/*   Updated: 2019/03/27 20:06:35 by pholster      ########   odam.nl         */
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
	value -= num;
	if (value < 0)
		value *= -1;
	while (i < n)
	{
		value *= 10;
		num = (long long)value;
		next = (value - num) * 10;
		if ((long long)next >= 5 && i + 1 == n)
			value += 1;
		ft_putnbr(value);
		value -= num;
		i++;
	}
}
