/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del_ttask.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:57:18 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:57:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

#include "ft_thpool.h"

void	*ft_del_ttask(t_ttask **task)
{
	if (task == NULL || *task == NULL)
		return (NULL);
	pthread_mutex_destroy(&(*task)->lock);
	pthread_cond_destroy(&(*task)->cond_completed);
	ft_memdel((void**)task);
	return (NULL);
}
