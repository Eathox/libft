/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 14:42:10 by pholster       #+#    #+#                */
/*   Updated: 2019/01/16 13:51:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	unsigned int	i;

	i = 0;
	if (n == -2147483648)
		i++;
	if (n == -2147483648)
		n = n / 10;
	if (n < 0)
		i++;
	if (n < 0)
		n = -n;
	while (n >= 0)
	{
		i++;
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (i);
}
