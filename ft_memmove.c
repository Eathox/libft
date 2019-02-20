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
	unsigned char		*temp_dst;
	unsigned const char	*temp_src;

	if ((unsigned int)dst - (unsigned int)src >= len)
		ft_memcpy(dst, src, len);
	else
	{
		temp_dst = dst;
		temp_src = src;
		while (len > 0)
		{
			len--;
			temp_dst[len] = temp_src[len];
		}
	}
	return (dst);
}
