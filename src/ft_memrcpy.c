/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:17:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

/*
** make it use 8 by 8 long long cpy
*/

void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*temp_dst;
	unsigned const char	*temp_src;

	temp_dst = dst;
	temp_src = src;
	while (len > 0)
	{
		len--;
		temp_dst[len] = temp_src[len];
	}
	return (dst);
}
