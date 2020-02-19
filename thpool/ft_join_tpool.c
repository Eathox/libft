/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_join_tpool.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:39:56 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:39:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/thpool.h"
#include "priv.h"

static t_bool	threads_done(t_tpool *pool)
{
	size_t	i;

	i = 0;
	while (i < pool->size)
	{
		if (pool->threads[i]->running_task == TRUE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void			ft_join_tpool(t_tpool *pool)
{
	t_bool	all_done;

	all_done = FALSE;
	if (pool == NULL)
		return ;
	pthread_mutex_lock(&pool->tasks->lock);
	while (all_done == FALSE)
	{
		while (pool->tasks->size != 0)
			pthread_cond_wait(&pool->tasks->cond_empty, &pool->tasks->lock);
		all_done = threads_done(pool);
	}
	pthread_mutex_unlock(&pool->tasks->lock);
}
