/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_threadnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:42:11 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 22:21:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"
#include "../includes/libft.h"

static void	*runfnc(void *param)
{
	t_task *task;

	task = (t_task *)param;
	ft_taskrunfnc(task);
	free(task);
	return (NULL);
}

t_bool		ft_threadnew(pthread_t *thread, void (*f)(), size_t count, ...)
{
	va_list	args;
	t_task	*task;

	if (count > 5 || thread == NULL || f == NULL)
		return (TRUE);
	task = (t_task *)ft_memalloc(sizeof(t_task));
	va_start(args, count);
	ft_tasksetinfo(task, f, count, args);
	va_end(args);
	if (pthread_create(thread, NULL, &runfnc, (void *)task) == 0)
		return (FALSE);
	free(task);
	return (TRUE);
}
