#include <stdlib.h>

#include "types/include/types.h"
#include "../include/mem.h"

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
