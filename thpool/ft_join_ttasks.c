/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_join_ttasks.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:39:56 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:39:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/thpool.h"

void	ft_join_ttasks(t_ttask **tasks, size_t len)
{
	size_t	i;

	i = 0;
	if (tasks == NULL)
		return ;
	while (i < len)
	{
		ft_join_ttask(tasks[i]);
		i++;
	}
}
