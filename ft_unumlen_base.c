/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unumlen_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/14 15:51:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unumlen_base(unsigned long long value, int base)
{
	int	len;

	len = 0;
	if (base < 2 || base > 36)
		return (0);
	while (base != -1)
	{
		len++;
		value = value / base;
		if (value == 0)
			break ;
	}
	return (len);
}
