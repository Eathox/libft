/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/03 14:52:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen_base(int value, int base)
{
	unsigned int	num;
	int				len;

	num = ft_abs(value);
	len = 0;
	if (value < 0 && base == 10)
		len++;
	while (value != -1)
	{
		len++;
		num = num / base;
		if (num == 0)
			break ;
	}
	return (len);
}
