/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:37:30 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:37:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	dstlen;

	dstlen = ft_strnlen(src, n);
	ft_memcpy(dst, src, dstlen);
	ft_bzero(&dst[dstlen], n - dstlen);
	return (dst);
}
