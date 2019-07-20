/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threadpool.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:26:14 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 17:17:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THREADPOOL_H
# define FT_THREADPOOL_H
# include "libft.h"
# include <pthread.h>
# include <stdatomic.h>

typedef	enum	e_state
{
	IDLE,
	ACTIVE,
	LOCKED
}				t_state;

typedef struct	s_task
{
	void			(*fnc)();
	char			param_count;
	void			*params[5];
	struct s_task	*next;
}				t_task;

typedef struct	s_thread
{
	pthread_t		thread;
	struct s_pool	*pool;
	t_state			state;
}				t_thread;

typedef struct	s_pool
{
	t_thread		**threads;
	t_task			*que;
	t_task			*last;
	atomic_char		state;
	t_bool			terminating;
	t_bool			suspended;
	size_t			size;
}				t_pool;

t_bool			ft_pooldone(t_pool *pool);
t_bool			ft_poolque(t_pool *pool, void (*f)(), size_t count, ...);
t_bool			ft_taskrunfnc(t_task *task);
t_bool			ft_threadnew(pthread_t *thread, void (*f)(), size_t count, ...);
t_pool			*ft_poolnew(size_t size);
void			*ft_threadmanager(void *param);
void			ft_pooldel(t_pool **pool);
void			ft_pooljoin(t_pool *pool);
t_task			*ft_tasksetinfo(t_task *task, void (*f)(), size_t count,
					va_list params);

#endif
