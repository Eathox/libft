/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_tpool.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 16:46:03 by dkroeke       #+#    #+#                 */
/*   Updated: 2020/02/02 21:34:03 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "thpool.h"
#include "priv.h"

static t_bool	alloc_queues(t_tpool *pool)
{
	pool->tasks = ft_new_tqueue();
	if (pool->tasks == NULL)
		return (FALSE);
	return (TRUE);
}

t_tpool			*ft_new_tpool(size_t size, t_uint64 flags)
{
	t_tpool		*pool;

	pool = ft_memalloc(sizeof(t_tpool));
	if (pool == NULL)
		return (NULL);
	pool->size = size;
	pool->flags = flags;
	if (alloc_queues(pool) == FALSE)
		return (ft_del_tpool(&pool));
	if ((pool->flags & TFLAG_POOL_ALLOC_ON_EXEC) == 0)
	{
		if (ft_alloc_tpool_tthreads(&pool) == FALSE)
			return (ft_del_tpool(&pool));
	}
	return (pool);
}
