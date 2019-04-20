/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threadpool.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:26:14 by pholster       #+#    #+#                */
/*   Updated: 2019/04/20 22:44:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADPOOL_H
# define FT_THREADPOOL_H
# include "libft.h"
# include <pthread.h>
# include <stdatomic.h>

# define POOL_SIZE	4

enum	e_state
{
	idle,
	active,
	locked
};

typedef struct	s_task
{
	void					(*fnc)(void *);
	void					*param;
	_Atomic(struct	s_task)	*next;
}				t_task;

typedef struct	s_thread
{
	pthread_t				thread;
	struct s_pool			*pool;
	_Atomic(enum e_state)	state;
}				t_thread;

typedef struct	s_pool
{
	t_thread				*threads[POOL_SIZE];
	_Atomic(t_task)			*que;
	_Atomic(t_task)			*last;
	_Atomic(enum e_state)	state;
	char					terminating;
	char					suspended;
}				t_pool;

int				ft_pooldone(t_pool *pool);
int				ft_poolque(t_pool *pool, void(*f)(void *), void *param);
t_pool			*ft_poolcreate(void);
void			ft_pooldelete(t_pool **pool);
void			ft_pooljoin(t_pool *pool);
void			*ft_threadmanager(void *param);

#endif
