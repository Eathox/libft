#include "mem.h"

/*
** * Allocates size amount of memory and sets it all to 0x0
** * Returns NULL if the allocation failed or if size is 0
*/
void *ft_memalloc(
	size_t size
) {
	return (ft_calloc(1, size));
}
