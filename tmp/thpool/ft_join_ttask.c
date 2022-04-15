#include <pthread.h>

#include "thpool.h"

void ft_join_ttask(t_ttask *task) {
    if (task == NULL)
        return;
    pthread_mutex_lock(&task->lock);
    while (task->completed == false)
        pthread_cond_wait(&task->cond_completed, &task->lock);
    pthread_mutex_unlock(&task->lock);
}
