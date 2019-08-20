/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	*ft_memrchr(void *str, int c, size_t len)
{
	unsigned char	*temp_str;

	temp_str = (unsigned char *)str;
	while (len > 0)
	{
		len--;
		if (temp_str[len] == (unsigned char)c)
			return (&temp_str[len]);
	}
	return (NULL);
}
