#include "../include/mem.h"

void *ft_memalloc(
    size_t size
) {
    return ft_calloc(1, size);
}
