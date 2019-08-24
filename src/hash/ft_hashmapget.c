/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapget.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 12:54:42 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 13:07:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_string.h"

void	*ft_hashmapget(t_hashmap *hashmap, char *key)
{
	t_hashlist	*current;
	size_t		index;

	index = hashmap->f(key) % hashmap->size;
	current = hashmap->arr[index];
	while (current != NULL && ft_strequ(current->key, key) == FALSE)
		current = current->next;
	if (current == NULL)
		return (NULL);
	return (current->value);
}
