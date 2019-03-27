/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbytes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:13:31 by pholster       #+#    #+#                */
/*   Updated: 2019/03/27 16:27:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putbytes(void *bytes, size_t n)
{
	size_t	i;
	size_t	byt;
	char	*byts;

	byt = 0;
	byts = (char *)bytes;
	while (byt < n)
	{
		i = 8;
		while (i > 0)
		{
			if (byts[byt] & ((long long)1 << (i - 1)))
				ft_putchar('1');
			else
				ft_putchar('0');
			i--;
		}
		byt++;
		if (n != 0)
			ft_putchar(' ');
	}
}
