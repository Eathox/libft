/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   priv.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 17:51:50 by pholster       #+#    #+#                */
/*   Updated: 2020/02/15 17:51:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRIV_H
# define FT_PRIV_H

#include "ft/thpool.h"

t_tthread			*ft_new_tthread(t_tpool *pool, size_t num,
									void *(*f)(void *));
t_tqueue			*ft_new_tqueue(void);
t_bool				ft_alloc_tpool_tthreads(t_tpool **pool);

void				*ft_del_tthread(t_tthread **thread);
void				*ft_del_tqueue(t_tqueue **queue);

void				ft_run_ttask(t_ttask *task);
void				ft_get_ttask(t_tthread *thread);
void				ft_complete_ttask(t_ttask *task);
t_ttask				*ft_add_tqueue_ttask(t_tqueue *queue, t_ttask *task);

void				*ft_worker_tthread(void *param);

#endif
