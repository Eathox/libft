/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:17:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t				i;
	unsigned char		*temp_dst;
	unsigned const char	*temp_src;

	i = 0;
	temp_dst = dst;
	temp_src = src;
	while (i < len)
	{
		temp_dst[i] = temp_src[i];
		if (temp_src[i] == (unsigned char)c)
			return (&temp_dst[i + 1]);
		i++;
	}
	return (NULL);
}
