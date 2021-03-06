/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_worker_tthread.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:10 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/07 16:40:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "thpool.h"
#include "priv.h"

void	*ft_worker_tthread(void *param) {
	t_tthread	*thread;

	thread = (t_tthread *)param;
	while ((thread->pool->flags & TFLAG_POOL_TERMINATE) == 0)
	{
		ft_get_ttask(thread);
		if (thread->task == NULL)
			continue ;
		ft_run_ttask(thread->task);
		ft_complete_ttask(thread->task);
		thread->task = NULL;
		thread->running_task = false;
	}
	return (NULL);
}
