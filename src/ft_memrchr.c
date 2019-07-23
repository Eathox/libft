/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:17:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

void	*ft_memrchr(const void *str, int c, size_t len)
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
