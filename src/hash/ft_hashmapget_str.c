/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapget_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 12:54:42 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:16:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_string.h"

void	*ft_hashmapget_str(t_hashmap *map, void *key)
{
	return (ft_hashmapget(map, key, ft_strlen(key) + 1));
}
