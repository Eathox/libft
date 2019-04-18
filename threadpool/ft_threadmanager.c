/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/04/18 18:10:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

//TODO ADD X LOCKS AND ATOMIC OPERATIONS

static int	gettask(t_pool *pool, t_thread *self, t_list **lst)
{
	enum e_state	state;
	int				i;

	i = 0;
	while (i < POOL_SIZE && pool->threads[i] != self)
	{
		if ((pool->threads[i])->state != active)
			return (FALSE);
		i++;
	}
	if (pool->state == locked || pool->state == suspended)
		return (FALSE);
	*lst = pool->que;
	if (*lst != NULL)
	{
		state = pool->state;
		pool->state = locked;
		pool->que = (*lst)->next;
		pool->state = state;
		return (TRUE);
	}
	return (FALSE);
}

void		*ft_threadmanager(void *param)
{
	int			ret;
	t_list		*lst;
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	lst = NULL;
	self = param;
	pool = self->pool;
	while (pool != NULL && pool->state != terminating)
	{
		ret = gettask(pool, self, &lst);
		if (ret != FALSE)
		{
			self->state = active;
			task = (t_task *)lst->content;
			if (task != NULL)
				task->fnc(task->param);
			ft_lstdelone(&lst, &ft_lstdelmem);
			self->state = idle;
		}
	}
	return (NULL);
}
