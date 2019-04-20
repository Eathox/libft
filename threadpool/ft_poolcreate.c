/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolcreate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/20 22:43:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static t_thread	*threadcreate(t_pool *pool)
{
	int			ret;
	t_thread	*thread;

	thread = (t_thread *)ft_memalloc(sizeof(t_thread));
	if (thread == NULL)
		return (NULL);
	thread->state = idle;
	thread->pool = pool;
	ret = pthread_create(&(thread->thread), NULL, &ft_threadmanager, thread);
	if (ret != 0)
	{
		free(thread);
		return (NULL);
	}
	return (thread);
}

t_pool			*ft_poolcreate(void)
{
	int			i;
	t_pool		*pool;

	if (POOL_SIZE <= 0)
		return (NULL);
	pool = (t_pool *)ft_memalloc(sizeof(t_pool));
	if (pool == NULL)
		return (NULL);
	pool->que = NULL;
	pool->terminating = FALSE;
	pool->suspended = TRUE;
	pool->state = active;
	i = 0;
	while (i < POOL_SIZE)
	{
		pool->threads[i] = threadcreate(pool);
		if (pool->threads[i] == NULL)
		{
			ft_pooldelete(&pool);
			return (NULL);
		}
		i++;
	}
	pool->suspended = FALSE;
	return (pool);
}
