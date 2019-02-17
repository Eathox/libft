/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 22:43:41 by pholster       #+#    #+#                */
/*   Updated: 2019/02/17 22:43:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	char	*dup;

	dup = ft_memalloc(n);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, src, n);
	return (dup);
}
