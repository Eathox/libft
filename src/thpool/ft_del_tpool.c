/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del_tpool.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:38 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:41:38 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_mem.h"

#include "ft_thpool.h"

static void	del_threads(t_tpool *pool)
{
	size_t	i;

	i = 0;
	if (pool->threads == NULL)
		return ;
	pthread_cond_broadcast(&pool->tasks->cond_not_empty);
	while (i < pool->size)
	{
		pthread_join(pool->threads[i]->id, NULL);
		th_del_tthread(&pool->threads[i]);
		i++;
	}
	free(pool->threads);
}

void		*ft_del_tpool(t_tpool **pool)
{
	if (pool == NULL || *pool == NULL)
		return (NULL);
	(*pool)->flags |= TFLAG_POOL_TERMINATE;
	del_threads(*pool);
	th_del_tqueue(&(*pool)->tasks);
	ft_memdel((void**)pool);
	return (NULL);
}
