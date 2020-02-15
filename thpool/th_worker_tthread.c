/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   th_worker_tthread.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:10 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:40:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/thpool.h"

void	*th_worker_tthread(void *param)
{
	t_tthread	*thread;

	thread = (t_tthread *)param;
	while ((thread->pool->flags & TFLAG_POOL_TERMINATE) == 0)
	{
		th_get_ttask(thread);
		if (thread->task== NULL)
			continue ;
		th_run_ttask(thread->task);
		th_complete_ttask(thread->task);
		thread->task = NULL;
		thread->running_task = FALSE;
	}
	return (NULL);
}

