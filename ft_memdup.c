/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 22:43:41 by pholster       #+#    #+#                */
/*   Updated: 2019/03/16 23:06:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t len)
{
	char	*dup;

	dup = ft_memalloc(len);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, src, len);
	return (dup);
}
