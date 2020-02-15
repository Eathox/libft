/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_run_thread.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 15:25:32 by pholster       #+#    #+#                */
/*   Updated: 2020/02/09 15:25:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/thpool.h"

static void	*run_task(void *param)
{
	t_ttask *task;

	task = (t_ttask*)param;
	th_run_ttask(task);
	th_complete_ttask(task);
	return (NULL);
}

t_ttask		*ft_run_thread(pthread_t *thread, t_ttask *task)
{
	if (task == NULL)
		return (NULL);
	if (pthread_create(thread, NULL, &run_task, (void *)task) == 0)
		return (NULL);
	return (task);
}
