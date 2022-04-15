#include <stdarg.h>

#include "ft/mem.h"

#include "thpool.h"

static bool init_lock_cond(t_ttask *task) {
    if (pthread_mutex_init(&task->lock, NULL) != 0)
        return false;
    if (pthread_cond_init(&task->cond_completed, NULL) != 0)
        return false;
    return true;
}

static void set_params(t_ttask *task, va_list parameters) {
    size_t i;

    i = 0;
    while (i < task->param_count) {
        task->params[i] = va_arg(parameters, void *);
        i++;
    }
}

t_ttask *ft_new_ttask(void *(*fnc)(), t_uint64 flags, size_t param_count, ...) {
    va_list parameters;
    t_ttask *task;

    if (param_count > MAX_TTASK_PARAMS)
        return NULL;
    task = ft_memalloc(sizeof(t_ttask));
    if (task == NULL)
        return NULL;
    task->f = fnc;
    task->flags = flags;
    task->param_count = param_count;
    if (init_lock_cond(task) == false)
        return ft_del_ttask(&task);
    va_start(parameters, param_count);
    set_params(task, parameters);
    va_end(parameters);
    return task;
}
