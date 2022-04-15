#include "ft/mem.h"

#include "priv.h"
#include "thpool.h"

void *ft_del_tthread(t_tthread **thread) {
    if (thread == NULL || *thread == NULL)
        return NULL;
    ft_memdel((void **)thread);
    return NULL;
}
