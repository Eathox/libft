#include "ft/mem.h"

#include "priv.h"
#include "thpool.h"

static bool alloc_queues(t_tpool *pool) {
    pool->tasks = ft_new_tqueue();
    if (pool->tasks == NULL)
        return false;
    return true;
}

t_tpool *ft_new_tpool(size_t size, t_uint64 flags) {
    t_tpool *pool;

    pool = ft_memalloc(sizeof(t_tpool));
    if (pool == NULL)
        return NULL;
    pool->size = size;
    pool->flags = flags;
    if (alloc_queues(pool) == false)
        return ft_del_tpool(&pool);
    if ((pool->flags & TFLAG_POOL_ALLOC_ON_EXEC) == 0) {
        if (ft_alloc_tpool_tthreads(&pool) == false)
            return ft_del_tpool(&pool);
    }
    return pool;
}
