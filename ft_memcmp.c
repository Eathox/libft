/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:02 by pholster       #+#    #+#                */
/*   Updated: 2019/01/19 15:50:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*cs2;
	unsigned const char	*cs1;
	size_t				i;
	unsigned char		a;
	unsigned char		b;

	i = 0;
	cs1 = s1;
	cs2 = s2;
	while (i < n)
	{
		a = cs1[i];
		b = cs2[i];
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
