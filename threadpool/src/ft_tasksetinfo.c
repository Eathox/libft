/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tasksetinfo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:54:57 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 23:00:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/threadpool.h"
#include "../../includes/libft.h"

t_task	*ft_tasksetinfo(t_task *task, void (*f)(), size_t count, va_list params)
{
	size_t		i;

	i = 0;
	task->fnc = f;
	task->param_count = count;
	task->next = NULL;
	ft_bzero(task->params, sizeof(task->params));
	while (i < count)
	{
		task->params[i] = va_arg(params, void *);
		i++;
	}
	return (task);
}
