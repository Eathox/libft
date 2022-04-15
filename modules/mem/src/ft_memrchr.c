#include <string.h>

#include "types/include/types.h"
#include "../include/mem.h"

void *ft_memrchr(
	void const *mem,
	uint8_t c,
	size_t len
) {
	uint8_t const *mem_byte = mem;

	size_t i = len;
	while (i > 0) {
		i--;
		if (mem_byte[i] == c)
			return ((void *)(mem_byte + i));
	}
	return (NULL);
}
