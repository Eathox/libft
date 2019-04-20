/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolque.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/04/21 00:07:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static int	freeret(t_pool *pool, t_task *task, enum e_state state)
{
	free(task);
	atomic_store(&(pool->state), state);
	return (FALSE);
}

int			ft_poolque(t_pool *pool, void (*f)(void *), void *param)
{
	enum e_state	state;
	t_task			*task;

	if (pool == NULL || pool->terminating || f == NULL)
		return (FALSE);
	task = (t_task *)ft_memalloc(sizeof(t_task));
	if (task == NULL)
		return (FALSE);
	state = atomic_exchange(&(pool->state), locked);
	while (state == locked)
		state = atomic_exchange(&(pool->state), locked);
	task->fnc = f;
	task->param = param;
	task->next = NULL;
	if (pool->terminating)
		return(freeret(pool, task, state));
	if (pool->last == NULL)
		pool->que = task;
	else
		pool->last->next = task;
	pool->last = task;
	atomic_store(&(pool->state), state);
	return (TRUE);
}
