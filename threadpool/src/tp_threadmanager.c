/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tp_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/11 11:06:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threadpool.h"

static t_bool	gettask(t_pool *pool, t_thread *self, t_task **task)
{
	char	state;

	if (pool->suspended)
		return (FALSE);
	state = atomic_exchange(&(pool->state), LOCKED);
	if (state == LOCKED)
		return (FALSE);
	*task = (t_task *)pool->que;
	if (*task != NULL)
	{
		self->state = ACTIVE;
		pool->que = (*task)->next;
		if (*task == pool->last)
			pool->last = NULL;
	}
	atomic_store(&(pool->state), state);
	return (*task != NULL);
}

void			*tp_threadmanager(void *param)
{
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	task = NULL;
	self = param;
	pool = self->pool;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (gettask(pool, self, &task) != FALSE)
		{
			tp_taskrunfnc(task);
			free(task);
			self->state = IDLE;
		}
	}
	return (NULL);
}
