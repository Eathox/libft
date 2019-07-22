/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldone.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 22:45:56 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 23:00:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/threadpool.h"

t_bool		ft_pooldone(t_pool *pool)
{
	size_t		i;

	i = 0;
	if (pool == NULL)
		return (TRUE);
	while (i < pool->size)
	{
		if ((pool->threads[i])->state == ACTIVE)
			return (FALSE);
		i++;
	}
	return (pool->que == NULL);
}
