/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tp_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/15 14:43:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threadpool.h"
#include "ft_printf.h"
#include "libft.h"
#include <time.h>

#include <stdio.h>

static t_bool	gettask(t_pool *pool, t_thread *self, t_task **task)
{
	char	state;

	if (pool->suspended)
		return (FALSE);
	state = atomic_exchange(&(pool->state), LOCKED);
	if (state == LOCKED)
		return (FALSE);
	*task = (t_task *)pool->que;
	if (*task != NULL)
	{
		self->state = ACTIVE;
		pool->que = (*task)->next;
		if (*task == pool->last)
			pool->last = NULL;
	}
	atomic_store(&(pool->state), state);
	return (*task != NULL);
}

static void		runtask(t_pool *pool, t_thread *self, t_task *task,
	float *waittime)
{
	clock_t		start;
	float		runtime;
	char		*timecolor;
	char		*color;

	if (pool->tracktime == TRUE)
		start = clock();
	tp_taskrunfnc(task);
	free(task);
	if (pool->tracktime == TRUE)
	{
		runtime = (float)(clock() - start) / CLOCKS_PER_SEC;
		color = ft_strformat("\e[38;5;%lum", (self->number % 15) + 1);
		if (runtime > *waittime)
			timecolor = "\e[38;5;2m";
		else
			timecolor = "\e[38;5;1m";
		ft_printf("%spool->thread[%zu]%{} - %sRuntime %f : Waittime: %f%{}\n",
			color, self->number, timecolor, runtime, *waittime);
		ft_strdel(&color);
		*waittime = 0;
	}
	self->state = IDLE;
}

void			*tp_threadmanager(void *param)
{
	clock_t		start;
	float		waittime;
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	task = NULL;
	self = param;
	pool = self->pool;
	waittime = 0;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (pool->tracktime == TRUE)
			start = clock();
		if (gettask(pool, self, &task) != FALSE)
			runtask(pool, self, task, &waittime);
		else if (pool->tracktime == TRUE)
			waittime += (float)(clock() - start) / CLOCKS_PER_SEC;
	}
	return (NULL);
}
