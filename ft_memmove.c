/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:35:27 by pholster       #+#    #+#                */
/*   Updated: 2019/07/14 14:45:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if ((size_t)dst - (size_t)src >= len)
		ft_memcpy(dst, src, len);
	else
		ft_memrcpy(dst, src, len);
	return (dst);
}
