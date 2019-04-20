/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolque.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/04/20 22:30:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

int		ft_poolque(t_pool *pool, void (*f)(void *), void *param)
{
	_Atomic(enum e_state)	state;
	_Atomic(t_task)			*task;

	if (pool == NULL || pool->terminating || f == NULL)
		return (FALSE);
	task = (_Atomic(t_task) *)ft_memalloc(sizeof(_Atomic(t_task)));
	if (task == NULL)
		return (FALSE);
	while (atomic_load(&(pool->state)) == locked)
		;
	state = atomic_exchange(&(pool->state), locked);
	task->fnc = f;
	task->param = param;
	task->next = NULL;
	if (pool->terminating)
		return (FALSE);
	if (atomic_load(&(pool->last)) == NULL)
		atomic_store(&(pool->que), task);
	else
		atomic_store(&(pool->last->next), task);
	atomic_store(&(pool->last), task);
	atomic_store(&(pool->state), state);
	return (TRUE);
}
