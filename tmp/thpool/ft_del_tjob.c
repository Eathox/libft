#include "ft/mem.h"

#include "priv.h"

void		*ft_del_tjob(t_tjob **job, bool delete_task) {
	if (job == NULL || *job == NULL)
		return (NULL);
	if (delete_task == true)
		ft_del_ttask(&(*job)->task);
	ft_memdel((void**)job);
	return (NULL);
}
