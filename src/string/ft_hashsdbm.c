/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashsdbm.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:01:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

size_t	ft_hashsdbm(char *str)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 0;
	while (str[i] != '\0')
	{
		hash = str[i] + (hash << 6) + (hash << 16) - hash;
		i++;
	}
	return (hash);
}
