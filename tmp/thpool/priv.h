#ifndef FT_PRIV_H
# define FT_PRIV_H

# include "ft/thpool.h"

typedef struct s_tjob		t_tjob;
typedef	struct s_tthread	t_tthread;

struct				s_tjob
{
	t_ttask			*task;
	t_tjob			*next;
};

typedef struct		s_tqueue
{
	t_tjob			*first;
	t_tjob			*last;
	size_t			size;
	pthread_cond_t	cond_empty;
	pthread_cond_t	cond_not_empty;
	pthread_mutex_t	lock;
}					t_tqueue;

struct				s_tthread
{
	pthread_t		id;
	size_t			num;
	bool			running_task;
	t_ttask			*task;
	t_tpool			*pool;
};

t_tjob				*ft_new_tjob(t_ttask *task);
t_tthread			*ft_new_tthread(t_tpool *pool, size_t num,
									void *(*f)(void *));
t_tqueue			*ft_new_tqueue(void);
bool				ft_alloc_tpool_tthreads(t_tpool **pool);

void				*ft_del_tjob(t_tjob **job, bool delete_task);
void				*ft_del_tthread(t_tthread **thread);
void				*ft_del_tqueue(t_tqueue **queue);

void				ft_run_ttask(t_ttask *task);
void				ft_get_ttask(t_tthread *thread);
void				ft_complete_ttask(t_ttask *task);
t_ttask				*ft_add_tqueue_ttask(t_tqueue *queue, t_ttask *task);

void				*ft_worker_tthread(void *param);

#endif
