/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_complete_ttask.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 14:40:34 by pholster       #+#    #+#                */
/*   Updated: 2020/02/09 14:40:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/thpool.h"
#include "priv.h"

void	ft_complete_ttask(t_ttask *task)
{
	if ((task->flags & TFLAG_TASK_NO_DELETE) != 0)
	{
		pthread_mutex_lock(&task->lock);
		pthread_cond_broadcast(&task->cond_completed);
		pthread_mutex_unlock(&task->lock);
	}
	else
		ft_del_ttask(&task);
}
