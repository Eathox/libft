/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashsdbm.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 18:13:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hashsdbm(char *str)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
	while (str[i] != '\0')
	{
		if ((i % 2) == 0)
			hash = ft_toupper(str[i]) + (hash << 6) + (hash << 16) - hash;
		else
			hash = ft_tolower(str[i]) + (hash << 6) + (hash << 16) - hash;
		i++;
	}
	return (hash);
}
