/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/18 12:12:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static t_task	*gettask(t_pool *pool, t_thread *self, t_list **lst)
{
	int			i;

	i = 0;
	while (i < POOL_SIZE && pool->threads[i] != self)
	{
		if ((pool->threads[i])->state == idle)
			return (NULL);
		i++;
	}
	if (pool->que != NULL)
	{
		*lst = pool->que;
		pool->que = (*lst)->next;
		return ((t_task *)(*lst)->content);
	}
	return (NULL);
}

void			*ft_threadmanager(void *param)
{
	t_list		*lst;
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	lst = NULL;
	self = param;
	pool = self->pool;
	while (pool->active == TRUE)
	{
		task = gettask(pool, self, &lst);
		if (task != NULL)
		{
			self->state = working;
			task->ret = task->fnc(task->param);
			ft_lstadd(&(pool->complete), lst);
		}
		self->state = idle;
	}
	return (NULL);
}
