#include "ft/mem.h"

#include "thpool.h"
#include "priv.h"

t_tqueue	*ft_new_tqueue(void) {
	t_tqueue	*queue;

	queue = ft_memalloc(sizeof(t_tqueue));
	if (queue == NULL)
		return (NULL);
	if (pthread_mutex_init(&queue->lock, NULL) != 0)
		return (ft_del_tqueue(&queue));
	if (pthread_cond_init(&queue->cond_empty, NULL) != 0)
		return (ft_del_tqueue(&queue));
	if (pthread_cond_init(&queue->cond_not_empty, NULL) != 0)
		return (ft_del_tqueue(&queue));
	return (queue);
}
