/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooljoin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 22:45:56 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 23:00:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/threadpool.h"

void		ft_pooljoin(t_pool *pool)
{
	if (pool == NULL)
		return ;
	while (ft_pooldone(pool) == FALSE)
		;
}
