/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		temp_c;
	const unsigned char	*temp_src;
	unsigned char		*temp_dst;

	i = 0;
	temp_c = c;
	temp_dst = dst;
	temp_src = src;
	while (i < len)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == temp_c)
			return (&temp_dst[i + 1]);
		i++;
	}
	return (NULL);
}
