#include <stdlib.h>

#include "../types/types.h"
#include "mem.h"

/*
** * Duplicates len amount of bytes from mem
** * Returns NULL if the allocation of the duplicate failed or if len is 0
*/
void *ft_memdup(
	void const *mem,
	size_t len
) {
	if (len == 0)
		return (NULL);

	void *dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, mem, len);
	return (dup);
}
