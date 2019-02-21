/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster       #+#    #+#                */
/*   Updated: 2019/01/17 15:57:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*temp_dst;
	unsigned const char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	while (n > 0)
	{
		n--;
		temp_dst[n] = temp_src[n];
	}
	return (dst);
}
