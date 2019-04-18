/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threadpool.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:26:14 by pholster       #+#    #+#                */
/*   Updated: 2019/04/18 16:46:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADPOOL_H
# define FT_THREADPOOL_H
# include "libft.h"
# include <pthread.h>

# define POOL_SIZE	4

enum	e_state
{
	idle,
	working
};

typedef struct	s_thread
{
	pthread_t		thread;
	struct s_pool	*pool;
	enum e_state	state;
}				t_thread;

typedef struct	s_pool
{
	t_thread		*threads[POOL_SIZE];
	t_list			*que;
	char			active;
}				t_pool;

typedef struct	s_task
{
	void			(*fnc)(void *);
	void			*param;
}				t_task;

int				ft_pooldone(t_pool *pool);
int				ft_poolque(t_pool *pool, void(*f)(void *), void *param);
t_pool			*ft_poolcreate(void);
void			ft_pooldelete(t_pool **pool);
void			ft_pooljoin(t_pool *pool);
void			*ft_threadmanager(void *param);

#endif
