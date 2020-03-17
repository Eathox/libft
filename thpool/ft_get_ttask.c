/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_ttask.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:55 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:41:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "thpool.h"
#include "priv.h"

static void	exract_task(t_tthread *thread, t_tqueue *tasks)
{
	t_tjob	*job;

	job = tasks->first;
	thread->task = job->task;
	tasks->first = job->next;
	ft_del_tjob(&job, FALSE);
	if (tasks->first == NULL)
		tasks->last = NULL;
	tasks->size--;
	if (tasks->size == 0)
		pthread_cond_broadcast(&tasks->cond_empty);
}

void		ft_get_ttask(t_tthread *thread)
{
	t_tpool		*pool;
	t_tqueue	*tasks;

	pool = thread->pool;
	tasks = pool->tasks;
	pthread_mutex_lock(&tasks->lock);
	while ((pool->flags & TFLAG_POOL_TERMINATE) == 0 && tasks->size == 0)
		pthread_cond_wait(&tasks->cond_not_empty, &tasks->lock);
	if ((pool->flags & TFLAG_POOL_TERMINATE) == 0)
	{
		thread->running_task = TRUE;
		exract_task(thread, tasks);
	}
	pthread_mutex_unlock(&tasks->lock);
}
