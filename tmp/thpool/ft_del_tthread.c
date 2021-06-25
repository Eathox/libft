#include "ft/mem.h"

#include "thpool.h"
#include "priv.h"

void	*ft_del_tthread(t_tthread **thread) {
	if (thread == NULL || *thread == NULL)
		return (NULL);
	ft_memdel((void**)thread);
	return (NULL);
}
