/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapget.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 12:54:42 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:16:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"

void	*ft_hashmapget(t_hashmap *map, void *key, size_t keysize)
{
	t_hashlist	*current;
	size_t		index;

	index = map->f(key) % map->size;
	current = map->arr[index];
	while (current != NULL && hs_keyequ(current, key, keysize) == FALSE)
		current = current->next;
	if (current == NULL)
		return (NULL);
	return (current->value);
}
