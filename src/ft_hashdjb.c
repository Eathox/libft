/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashdjb.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:09 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 18:13:32 by pholster      ########   odam.nl         */
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
		hash = ((hash << 5) + hash) + str[i];
		i++;
	}
	return (hash);
}
