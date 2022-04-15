#include "ft/mem.h"

#include "priv.h"
#include "thpool.h"

static void del_jobs(t_tjob *job) {
    t_tjob *next;

    while (job != NULL) {
        next = job->next;
        ft_del_tjob(&job, true);
        job = next;
    }
}

void *ft_del_tqueue(t_tqueue **queue) {
    if (queue == NULL || *queue == NULL)
        return NULL;
    del_jobs((*queue)->first);
    pthread_mutex_destroy(&(*queue)->lock);
    pthread_cond_destroy(&(*queue)->cond_empty);
    pthread_cond_destroy(&(*queue)->cond_not_empty);
    ft_memdel((void **)queue);
    return NULL;
}
