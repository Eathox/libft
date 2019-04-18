/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolque.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/04/18 18:09:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

int		ft_poolque(t_pool *pool, void (*f)(void *), void *param)
{
	// enum e_state	state;
	t_task			*task;
	t_list			*lst;

	if (pool == NULL || pool->state == terminating || f == NULL)
		return (FALSE);
	lst = ft_lstnew(NULL, 0);
	if (lst == NULL)
		return (FALSE);
	task = (t_task *)ft_memalloc(sizeof(t_task));
	if (task == NULL)
	{
		free(lst);
		return (FALSE);
	}
	// while (pool->state == locked)
	// 	;
	// state = pool->state;
	// pool->state = locked;
	task->fnc = f;
	task->param = param;
	lst->content = task;
	ft_lstaddbck(&(pool->que), lst);
	// pool->state = state;
	return (TRUE);
}
