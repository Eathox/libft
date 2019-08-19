/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapnew.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:05:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:20:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hashmap		*ft_hashmapnew(size_t size, size_t (*f)(char *))
{
	t_hashmap	*new;

	new = (t_hashmap *)ft_memalloc(sizeof(t_hashmap));
	if (new == NULL)
		return (NULL);
	new->arr = (void **)ft_memalloc(sizeof(void *) * size);
	if (new->arr == NULL)
	{
		free(new);
		return (NULL);
	}
	new->f = f;
	new->size = size;
	return (new);
}
