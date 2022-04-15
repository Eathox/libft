#include <stdlib.h>

#include "ft/mem.h"

#include "priv.h"
#include "thpool.h"

static void del_threads(t_tpool *pool) {
    size_t i;

    i = 0;
    if (pool->threads == NULL)
        return;
    pthread_mutex_lock(&pool->tasks->lock);
    pthread_cond_broadcast(&pool->tasks->cond_not_empty);
    pthread_mutex_unlock(&pool->tasks->lock);
    while (i < pool->size) {
        pthread_join(pool->threads[i]->id, NULL);
        ft_del_tthread(&pool->threads[i]);
        i++;
    }
    free(pool->threads);
}

void *ft_del_tpool(t_tpool **pool) {
    if (pool == NULL || *pool == NULL)
        return NULL;
    (*pool)->flags |= TFLAG_POOL_TERMINATE;
    del_threads(*pool);
    ft_del_tqueue(&(*pool)->tasks);
    ft_memdel((void **)pool);
    return NULL;
}
