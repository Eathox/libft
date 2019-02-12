/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/12 15:00:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen_base(long long value, int base)
{
	unsigned long long	num;
	int					len;

	len = (value < 0 && base == 10);
	num = (value < 0 && base == 10) ? -value : value;
	if (base < 2 || base > 36)
		return (0);
	while (value != -1)
	{
		len++;
		num = num / base;
		if (num == 0)
			break ;
	}
	return (len);
}
