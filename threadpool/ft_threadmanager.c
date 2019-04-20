/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/20 23:50:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static int	gettask(t_pool *pool, t_thread *self, t_task **task)
{
	enum e_state	state;

	if (pool->suspended)
		return (FALSE);
	state = atomic_exchange(&(pool->state), locked);
	if (state == locked)
		return (FALSE);
	*task = (t_task *)pool->que;
	if (*task != NULL)
	{
		self->state = active;
		pool->que = (*task)->next;
		if (*task == pool->last)
			pool->last = NULL;
	}
	atomic_store(&(pool->state), state);
	return (*task != NULL);
}

void		*ft_threadmanager(void *param)
{
	int			ret;
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	task = NULL;
	self = param;
	pool = self->pool;
	while (pool != NULL && pool->terminating == FALSE)
	{
		ret = gettask(pool, self, &task);
		if (ret != FALSE)
		{
			if (task->fnc != NULL)
				task->fnc(task->param);
			free(task);
			self->state = idle;
		}
	}
	return (NULL);
}
