#include "thpool.h"

static void	del_tasks(t_ttask *task) {
	t_ttask	*next;

	while (task != NULL)
	{
		next = task->next;
		ft_del_ttask(&task);
		task = next;
	}
}

void		*ft_del_ttask_all(t_ttask **task) {
	if (task == NULL || *task == NULL)
		return (NULL);
	del_tasks(*task);
	*task = NULL;
	return (NULL);
}
