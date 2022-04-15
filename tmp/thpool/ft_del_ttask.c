#include "ft/mem.h"

#include "thpool.h"

void *ft_del_ttask(t_ttask **task) {
    if (task == NULL || *task == NULL)
        return NULL;
    pthread_mutex_destroy(&(*task)->lock);
    pthread_cond_destroy(&(*task)->cond_completed);
    ft_memdel((void **)task);
    return NULL;
}
