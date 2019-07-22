/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolque.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 23:00:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/threadpool.h"
#include "../../includes/libft.h"

static t_bool	freeret(t_pool *pool, t_task *task, t_state state)
{
	free(task);
	atomic_store(&(pool->state), state);
	return (FALSE);
}

t_bool			ft_poolque(t_pool *pool, void (*f)(), size_t count, ...)
{
	va_list		params;
	t_state		state;
	t_task		*task;

	if (count > 5 || pool == NULL || pool->terminating || f == NULL)
		return (FALSE);
	task = (t_task *)ft_memalloc(sizeof(t_task));
	if (task == NULL)
		return (FALSE);
	state = atomic_exchange(&(pool->state), LOCKED);
	while (state == LOCKED)
		state = atomic_exchange(&(pool->state), LOCKED);
	va_start(params, count);
	ft_tasksetinfo(task, f, count, params);
	va_end(params);
	if (pool->terminating)
		return (freeret(pool, task, state));
	if (pool->last == NULL)
		pool->que = task;
	else
		pool->last->next = task;
	pool->last = task;
	atomic_store(&(pool->state), state);
	return (TRUE);
}
