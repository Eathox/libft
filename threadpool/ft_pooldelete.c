/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldelete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:53:48 by pholster       #+#    #+#                */
/*   Updated: 2019/04/20 23:40:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

static void	delque(t_pool *pool)
{
	t_task	*que;
	t_task	*temp;

	que = (t_task *)atomic_exchange(&(pool->que), NULL);
	while (que != NULL)
	{
		temp = que;
		que = (t_task *)que->next;
		free(temp);
	}
}

void		ft_pooldelete(t_pool **pool)
{
	t_thread	*thread;
	int			i;

	i = 0;
	if (pool == NULL || *pool == NULL)
		return ;
	(*pool)->terminating = TRUE;
	while (i < POOL_SIZE && (*pool)->threads[i] != NULL)
	{
		thread = (*pool)->threads[i];
		pthread_join(thread->thread, NULL);
		free(thread);
		i++;
	}
	delque(*pool);
	ft_memdel((void **)pool);
}
