#include "thpool.h"
#include "priv.h"

void	ft_complete_ttask(t_ttask *task) {
	if ((task->flags & TFLAG_TASK_NO_DELETE) != 0)
	{
		pthread_mutex_lock(&task->lock);
		task->completed = true;
		pthread_cond_broadcast(&task->cond_completed);
		pthread_mutex_unlock(&task->lock);
	}
	else
		ft_del_ttask(&task);
}
