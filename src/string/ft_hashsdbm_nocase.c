/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashsdbm_nocase.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:01:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hashsdbm_nocase(char *str)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
	while (str[i] != '\0')
	{
		hash = ft_tolower(str[i]) + (hash << 6) + (hash << 16) - hash;
		i++;
	}
	return (hash);
}
