/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:48:45 by pholster       #+#    #+#                */
/*   Updated: 2019/01/23 14:00:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[len] != '\0' && len < size)
		len++;
	while (src[i] != '\0' && (len + i) < (size - 1))
	{
		dst[(len + i)] = src[i];
		i++;
	}
	if ((len + i) != size)
		dst[(len + i)] = '\0';
	return (len + ft_strlen(src));
}
