/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;
	long long		*temp_dst_8;
	long long		*temp_src_8;

	i = 0;
	temp_dst_8 = dst;
	temp_src_8 = src;
	while (len - (i * 8) >= 8)
	{
		temp_dst_8[i] = temp_src_8[i];
		i++;
	}
	i *= 8;
	if (i >= len)
		return (dst);
	temp_dst = dst;
	temp_src = src;
	while (i < len)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
