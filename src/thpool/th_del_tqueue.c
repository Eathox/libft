/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   th_del_tqueue.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:22 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:41:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

#include "ft_thpool.h"

static void	del_tasks(t_ttask *task)
{
	t_ttask	*next;

	while (task != NULL)
	{
		next = task->next;
		ft_del_ttask(&task);
		task = next;
	}
}

void		*th_del_tqueue(t_tqueue **queue)
{
	if (queue == NULL || *queue == NULL)
		return (NULL);
	del_tasks((*queue)->first);
	pthread_mutex_destroy(&(*queue)->lock);
	pthread_cond_destroy(&(*queue)->cond_empty);
	pthread_cond_destroy(&(*queue)->cond_not_empty);
	ft_memdel((void**)queue);
	return (NULL);
}
