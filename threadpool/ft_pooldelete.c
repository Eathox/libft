/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldelete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:53:48 by pholster       #+#    #+#                */
/*   Updated: 2019/04/18 18:03:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

void		ft_pooldelete(t_pool **pool)
{
	t_thread	*thread;
	int			i;

	i = 0;
	if (pool == NULL || *pool == NULL)
		return ;
	(*pool)->state = terminating;
	while (i < POOL_SIZE && (*pool)->threads[i] != NULL)
	{
		thread = (*pool)->threads[i];
		pthread_join(thread->thread, NULL);
		free(thread);
		i++;
	}
	ft_lstdel(&((*pool)->que), &ft_lstdelmem);
	ft_memdel((void **)pool);
}
