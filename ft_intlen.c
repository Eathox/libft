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

int		ft_intlen(int value)
{
	return (ft_intlen_base(value, 10));
}

/*
int		ft_intlen(int value)
{
	unsigned int	i;

	i = 0;
	if (value == -2147483648)
		i++;
	if (value == -2147483648)
		value = value / 10;
	if (value < 0)
		i++;
	if (value < 0)
		value = -value;
	while (value >= 0)
	{
		i++;
		value = value / 10;
		if (value == 0)
			break ;
	}
	return (i);
}
*/