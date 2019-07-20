/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolnew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 22:21:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"
#include "../includes/libft.h"

static t_pool	*freeret(t_pool **pool)
{
	ft_pooldel(pool);
	return (NULL);
}

static t_thread	*threadnew(t_pool *pool)
{
	t_thread	*thread;

	thread = (t_thread *)ft_memalloc(sizeof(t_thread));
	if (thread == NULL)
		return (NULL);
	thread->state = IDLE;
	thread->pool = pool;
	if (pthread_create(&(thread->thread), NULL, &ft_threadmanager, thread) != 0)
	{
		free(thread);
		return (NULL);
	}
	return (thread);
}

t_pool			*ft_poolnew(size_t size)
{
	size_t		i;
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
	pool->size = size;
	pool->state = ACTIVE;
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
