/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   th_new_tqueue.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:19 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:40:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "ft/thpool.h"

t_tqueue	*th_new_tqueue(void)
{
	t_tqueue	*queue;

	queue = ft_memalloc(sizeof(t_tqueue));
	if (queue == NULL)
		return (NULL);
	if (pthread_mutex_init(&queue->lock, NULL) != 0)
		return (th_del_tqueue(&queue));
	if (pthread_cond_init(&queue->cond_empty, NULL) != 0)
		return (th_del_tqueue(&queue));
	if (pthread_cond_init(&queue->cond_not_empty, NULL) != 0)
		return (th_del_tqueue(&queue));
	return (queue);
}
