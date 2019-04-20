/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/20 22:50:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static int	gettask(t_pool *pool, t_thread *self, _Atomic(t_task) **task)
{
	// int				i;
	enum e_state	state;

	if (pool->suspended)
		return (FALSE);
	// i = 0;
	// while (i < POOL_SIZE && pool->threads[i] != self)
	// {
	// 	if (atomic_load(&((pool->threads[i])->state)) == active)
	// 		return (FALSE);
	// 	i++;
	// }
	state = atomic_exchange(&(pool->state), locked);
	if (state == locked)
		return (FALSE);
	*task = atomic_load(&(pool->que));
	if (*task != NULL)
	{
		atomic_store(&(self->state), active);
		atomic_store(&(pool->que), (*task)->next);
	}
	atomic_store(&(pool->state), state);
	return (*task != NULL);
}

void		*ft_threadmanager(void *param)
{
	int				ret;
	_Atomic(t_task)	*task;
	t_pool			*pool;
	t_thread		*self;

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
			//free(task);
			atomic_store(&(self->state), idle);
		}
	}
	return (NULL);
}
