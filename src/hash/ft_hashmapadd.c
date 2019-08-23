/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapadd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 16:38:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_memory.h"
#include "ft_string.h"

static t_hashlist	*newlst(char *key, void *value)
{
	t_hashlist	*new;

	new = (t_hashlist *)ft_memalloc(sizeof(t_hashlist));
	if (new == NULL)
		return (NULL);
	new->key = key;
	new->value = value;
	return (new);
}

t_bool				ft_hashmapadd(t_hashmap *hashmap, char *key, void *value)
{
	t_hashlist	*current;
	size_t		index;

	index = hashmap->f(key) % hashmap->size;
	current = hashmap->arr[index];
	if (current == NULL)
	{
		hashmap->arr[index] = newlst(key, value);
		return (hashmap->arr[index] != NULL);
	}
	while (current->next != NULL && ft_strequ(current->key, key) == FALSE)
		current = current->next;
	if (ft_strequ(current->key, key) == TRUE)
	{
		current->value = value;
		return (TRUE);
	}
	current->next = newlst(key, value);
	return (current->next != NULL);
}
