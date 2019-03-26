/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbytes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:13:31 by pholster       #+#    #+#                */
/*   Updated: 2019/03/26 18:08:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbytes(void *bytes, size_t n)
{
	size_t		i;
	long long	byt;

	while (n > 0)
	{
		i = 8;
		byt = *((long long *)bytes);
		byt >>= 8 * (n - 1);
		while (i > 0)
		{
			if ((byt >> (i - 1)) & 1)
				ft_putchar('1');
			else
				ft_putchar('0');
			i--;
		}
		n--;
		if (n != 0)
			ft_putchar(' ');
	}
}
