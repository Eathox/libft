#include "thpool.h"
#include "priv.h"

static void	*run_task(void *param) {
	t_ttask *task;

	task = (t_ttask*)param;
	ft_run_ttask(task);
	ft_complete_ttask(task);
	return (NULL);
}

t_ttask		*ft_run_thread(pthread_t *thread, t_ttask *task) {
	if (task == NULL)
		return (NULL);
	if (pthread_create(thread, NULL, &run_task, (void *)task) == 0)
		return (NULL);
	return (task);
}
