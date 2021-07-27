#include <stdint.h>
#include <stdlib.h>

#include "mem.h"

/*
** * Allocates (size * count) amount of memory and sets it all to 0x0
** * Returns NULL if the allocation failed or if the given values would overflow
** * If size, count or both are 0 it also returns NULL
*/
void *ft_calloc(
	size_t count,
	size_t size
) {
	if (count == 0 || size == 0)
		return (NULL);
	if (size > (SIZE_MAX / count))
		return (NULL);

	size_t final_size = size * count;
	void *mem = malloc(final_size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, final_size);
	return (mem);
}
