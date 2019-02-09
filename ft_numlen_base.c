/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/09 12:31:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen_base(long value, int base)
{
	unsigned long	num;
	int				len;

	len = 0;
	num = (value < 0 && base == 10) ? -value : value;
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
