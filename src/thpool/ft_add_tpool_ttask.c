/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_tpool_ttask.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:42:21 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/07 16:42:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "thpool.h"
#include "priv.h"

t_ttask		*ft_add_tpool_ttask(t_tpool *pool, t_ttask *task) {
	if (task == NULL || (pool->flags & TFLAG_POOL_TERMINATE) != 0)
		return (NULL);
	if (pool->alloced == false && (pool->flags & TFLAG_POOL_ALLOC_ON_EXEC) != 0)
	{
		if (ft_alloc_tpool_tthreads(&pool) == false)
			return (NULL);
	}
	return (ft_add_tqueue_ttask(pool->tasks, task));
}
