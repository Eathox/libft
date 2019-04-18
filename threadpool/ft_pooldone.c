/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldone.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 22:45:56 by pholster       #+#    #+#                */
/*   Updated: 2019/04/18 12:12:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

int		ft_poolcompleted(t_pool *pool)
{
	int			i;

	i = 0;
	while (i < POOL_SIZE)
	{
		if ((pool->threads[i])->state != idle)
			return (FALSE);
		i++;
	}
	return (pool->que == NULL);
}
