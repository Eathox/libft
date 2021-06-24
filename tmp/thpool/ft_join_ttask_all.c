/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_join_ttask_all.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:39:56 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/07 16:39:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "thpool.h"

void	ft_join_ttask_all(t_ttask *task) {
	while (task != NULL)
	{
		ft_join_ttask(task);
		task = task->next;
	}
}
