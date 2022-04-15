#include "priv.h"
#include "thpool.h"

static bool threads_done(t_tpool *pool) {
    size_t i;

    i = 0;
    while (i < pool->size) {
        if (pool->threads[i]->running_task == true)
            return false;
        i++;
    }
    return true;
}

void ft_join_tpool(t_tpool *pool) {
    bool all_done;

    all_done = false;
    if (pool == NULL)
        return;
    pthread_mutex_lock(&pool->tasks->lock);
    while (all_done == false) {
        while (pool->tasks->size != 0)
            pthread_cond_wait(&pool->tasks->cond_empty, &pool->tasks->lock);
        all_done = threads_done(pool);
    }
    pthread_mutex_unlock(&pool->tasks->lock);
}
