/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   th_alloc_tpool_tthreads.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:41:17 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 17:41:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "ft/thpool.h"

static t_bool	alloc_threads(t_tpool *pool)
{
	size_t	num;

	num = 0;
	pool->threads = ft_memalloc(sizeof(t_tthread *) * pool->size);
	if (pool->threads == NULL)
		return (FALSE);
	while (num < pool->size)
	{
		pool->threads[num] = th_new_tthread(pool, num, &th_worker_tthread);
		if (pool->threads[num] == NULL)
			return (FALSE);
		num++;
	}
	return (TRUE);
}

t_bool			th_alloc_tpool_tthreads(t_tpool **pool)
{
	if ((*pool)->alloced == TRUE)
		return (TRUE);
	if (alloc_threads(*pool) == FALSE)
	{
		ft_del_tpool(pool);
		return (FALSE);
	}
	(*pool)->alloced = TRUE;
	return (TRUE);
}
