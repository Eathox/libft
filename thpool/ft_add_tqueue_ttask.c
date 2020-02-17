/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_tqueue_ttask.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:42:21 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:42:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/thpool.h"
#include "priv.h"

static void	add_task_front(t_tqueue *queue, t_ttask *task)
{
	task->next = queue->first;
	queue->first = task;
	if (queue->last == NULL)
		queue->last = task;
}

static void	add_task_back(t_tqueue *queue, t_ttask *task)
{
	task->next = NULL;
	if (queue->first == NULL)
		queue->first = task;
	else
		queue->last->next = task;
	queue->last = task;
}

static void	add_task(t_tqueue *queue, t_ttask *task)
{
	if ((task->flags & TFLAG_TASK_HIGH_PRIOR) != 0)
		add_task_front(queue, task);
	else
		add_task_back(queue, task);
	queue->size++;
	if (queue->size == 1)
		pthread_cond_broadcast(&queue->cond_not_empty);
}

t_ttask		*ft_add_tqueue_ttask(t_tqueue *queue, t_ttask *task)
{
	if (task == NULL)
		return (NULL);
	task->completed = FALSE;
	pthread_mutex_lock(&queue->lock);
	add_task(queue, task);
	pthread_mutex_unlock(&queue->lock);
	return (task);
}