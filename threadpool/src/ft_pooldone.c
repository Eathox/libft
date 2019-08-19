/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldone.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 22:45:56 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:53:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threadpool.h"

t_bool		ft_pooldone(t_pool *pool)
{
	t_thread	*thread;
	size_t		current;

	current = pool->size;
	while (current > 0)
	{
		current--;
		thread = pool->threads[current];
		if (thread != NULL)
		{
			if (thread->state == ACTIVE)
				return (FALSE);
		}
	}
	return (pool->que == NULL);
}
