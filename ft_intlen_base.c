/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 10:39:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen_base(int value, int base)
{
	unsigned int	num;
	int				len;

	len = 0;
	num = (value < 0) ? -value : value;
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
