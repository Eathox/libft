/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashdjb.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 14:00:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

size_t	ft_hashdjb(char *str)
{
	size_t	hash;
	size_t	i;

	i = 0;
	hash = 5381;
	while (str[i] != '\0')
	{
		hash = str[i] + ((hash << 5) + hash);
		i++;
	}
	return (hash);
}
