/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_alloc_tpool_tthreads.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:41:17 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/07 17:41:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "thpool.h"
#include "priv.h"

static bool	alloc_threads(t_tpool *pool) {
	size_t	num;

	num = 0;
	pool->threads = ft_memalloc(sizeof(t_tthread *) * pool->size);
	if (pool->threads == NULL)
		return (false);
	while (num < pool->size)
	{
		pool->threads[num] = ft_new_tthread(pool, num, &ft_worker_tthread);
		if (pool->threads[num] == NULL)
			return (false);
		num++;
	}
	return (true);
}

bool			ft_alloc_tpool_tthreads(t_tpool **pool) {
	if ((*pool)->alloced == true)
		return (true);
	if (alloc_threads(*pool) == false)
	{
		ft_del_tpool(pool);
		return (false);
	}
	(*pool)->alloced = true;
	return (true);
}
