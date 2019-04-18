/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooltoggleactive.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 22:53:59 by pholster       #+#    #+#                */
/*   Updated: 2019/04/18 22:53:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

int		ft_pooltoggleactive(t_pool *pool)
{
	if (pool->state != suspended)
	{
		pool->state = suspended;
		return (FALSE);
	}
	pool->state = active;
	return (TRUE);
}
