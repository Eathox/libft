/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:15:03 by pholster       #+#    #+#                */
/*   Updated: 2019/03/28 19:49:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putprecision(long double value, size_t n)
{
	size_t		i;
	int			num;
	long double	next;
	long double	nextnext;
	long double	nextnextnext;

	i = 0;
	while (i < n)
	{
		value *= 10;
		num = (int)value;
		next = (value - num) * 10;
		nextnext = (next - (int)next) * 10;
		nextnextnext = (nextnext - (int)nextnext) * 10;
		if (num < 9)
		{
			if ((int)next == 9 && (int)nextnext >= 8 && (int)nextnextnext >= 7)
				num++;
			else if ((int)next >= 5 && (i + 1) == n)
				num++;
		}
		ft_putnbr(num);
		value -= num;
		i++;
	}
}

void		ft_putdouble(long double value, size_t n)
{
	long long	num;

	if (value < 0)
	{
		ft_putchar('-');
		value *= -1;
	}
	num = (long long)value;
	ft_putnbr(num);
	if (n == 0)
		return ;
	ft_putchar('.');
	value -= num;
	putprecision(value, n);
}
