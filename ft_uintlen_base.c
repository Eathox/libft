/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uintlen_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:12:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uintlen_base(unsigned int value, int base)
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
