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

#include "ft_mem.h"

static void	cpy_32(unsigned long long *dst_8, const unsigned long long *src_8,
					size_t *i, const size_t len)
{
	size_t			index_step;
	const size_t	step = 4;
	const size_t	len_8 = len / (2 * step);

	index_step = 0;
	while ((index_step + step) < len_8)
	{
		dst_8[index_step] = src_8[index_step];
		dst_8[index_step + 1] = src_8[index_step + 1];
		dst_8[index_step + 2] = src_8[index_step + 2];
		dst_8[index_step + 3] = src_8[index_step + 3];
		index_step += step;
	}
	*i = index_step * (2 * step);
}

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	cpy_32(dst, src, &i, len);
	temp_dst = dst;
	temp_src = src;
	while (i < len)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
