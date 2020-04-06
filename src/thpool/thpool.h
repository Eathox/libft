/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thpool.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 15:22:52 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/02 20:41:44 by dkroeke       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THPOOL_H
# define FT_THPOOL_H

# include <unistd.h>
# include <pthread.h>

# include "ft/types.h"
# include "ft/bool.h"

# define MAX_TTASK_PARAMS	4

typedef struct s_ttask		t_ttask;
typedef struct s_tpool		t_tpool;
typedef	struct s_tthread	t_tthread;
typedef	struct s_tqueue		t_tqueue;

typedef	enum		e_tflags
{
	TFLAG_POOL_TERMINATE = 0x1,
	TFLAG_POOL_ALLOC_ON_EXEC = 0x2,
	TFLAG_TASK_NO_DELETE = 0x4,
	TFLAG_TASK_HIGH_PRIOR = 0x8,
}					t_tflags;

typedef union		u_treturn
{
	t_int64			*i_ptr;
	double			*f_ptr;
	t_uint64		*u_ptr;
	t_bool			*b_ptr;
	char			*c_ptr;
	void			*v_ptr;
}					t_treturn;

struct				s_ttask
{
	void			*(*f)();
	void			*params[MAX_TTASK_PARAMS];
	size_t			param_count;
	t_uint64		flags;
	t_treturn		ret;
	t_bool			completed;
	pthread_cond_t	cond_completed;
	pthread_mutex_t	lock;
	t_ttask			*next;
};

struct				s_tpool
{
	size_t			size;
	t_tthread		*manager;
	t_tthread		**threads;
	t_tqueue		*tasks;
	t_bool			alloced;
	t_uint64		flags;
};

t_tpool				*ft_new_tpool(size_t size, t_uint64 flags);
t_ttask				*ft_new_ttask(void *(*fnc)(), t_uint64 flags,
								size_t param_count, ...);

void				*ft_del_tpool(t_tpool **pool);
void				*ft_del_ttask(t_ttask **task);
void				*ft_del_ttask_all(t_ttask **task);

void				ft_join_tpool(t_tpool *pool);
void				ft_join_ttask(t_ttask *task);
void				ft_join_ttasks(t_ttask **tasks, size_t len);
void				ft_join_ttask_all(t_ttask *task);

t_ttask				*ft_add_tpool_ttask(t_tpool *pool, t_ttask *task);

ssize_t				ft_get_core_count(void);
t_ttask				*ft_run_thread(pthread_t *thread, t_ttask *task);

#endif
