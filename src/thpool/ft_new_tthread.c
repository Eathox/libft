/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_tthread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:35 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/07 16:40:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "thpool.h"
#include "priv.h"

t_tthread		*ft_new_tthread(t_tpool *pool, size_t num, void *(*f)(void *)) {
	t_tthread		*thread;

	thread = ft_memalloc(sizeof(t_tthread));
	if (thread == NULL)
		return (NULL);
	thread->pool = pool;
	thread->num = num;
	if (pthread_create(&thread->id, NULL, f, thread) != 0)
		return (ft_del_tthread(&thread));
	return (thread);
}
