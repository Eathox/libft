/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolnew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/06/30 15:26:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static t_pool	*freeret(t_pool **pool)
{
	ft_pooldel(pool);
	return (NULL);
}

static t_thread	*threadnew(t_pool *pool)
{
	int			ret;
	t_thread	*thread;

	thread = (t_thread *)ft_memalloc(sizeof(t_thread));
	if (thread == NULL)
		return (NULL);
	thread->state = STATE_IDLE;
	thread->pool = pool;
	ret = pthread_create(&(thread->thread), NULL, &ft_threadmanager, thread);
	if (ret != 0)
	{
		free(thread);
		return (NULL);
	}
	return (thread);
}

static void		setdefualt(t_pool *pool, int size)
{
	pool->que = NULL;
	pool->terminating = FALSE;
	pool->size = size;
	pool->state = STATE_ACTIVE;
}

t_pool			*ft_poolnew(int size)
{
	int			i;
	t_pool		*pool;

	i = 0;
	if (size <= 0)
		return (NULL);
	pool = (t_pool *)ft_memalloc(sizeof(t_pool));
	if (pool == NULL)
		return (NULL);
	pool->threads = (t_thread **)ft_memalloc(sizeof(t_thread *) * size);
	if (pool->threads == NULL)
		return (freeret(&pool));
	setdefualt(pool, size);
	pool->suspended = TRUE;
	while (i < pool->size)
	{
		pool->threads[i] = threadnew(pool);
		if (pool->threads[i] == NULL)
			freeret(&pool);
		i++;
	}
	pool->suspended = FALSE;
	return (pool);
}
