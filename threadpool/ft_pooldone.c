/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldone.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 22:45:56 by pholster       #+#    #+#                */
/*   Updated: 2019/04/20 22:05:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

int		ft_pooldone(t_pool *pool)
{
	int			i;

	i = 0;
	if (pool == NULL)
		return (TRUE);
	while (i < POOL_SIZE)
	{
		if ((pool->threads[i])->state == active)
			return (FALSE);
		i++;
	}
	return (pool->que == NULL);
}
