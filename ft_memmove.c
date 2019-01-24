/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:35:27 by pholster       #+#    #+#                */
/*   Updated: 2019/01/20 17:21:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	if ((unsigned int)dst - (unsigned int)src >= len)
		ft_memcpy(dst, src, len);
	else
	{
		s1 = dst;
		s2 = src;
		while (len > 0)
		{
			len--;
			s1[len] = s2[len];
		}
	}
	return (dst);
}
