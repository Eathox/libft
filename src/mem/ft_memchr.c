#include <string.h>

#include "../types/types.h"
#include "mem.h"

/*
** * Searches len amount of bytes in mem for the first instance of c
** * Returns NULL if no instacne of c was found
*/
void *ft_memchr(
	void const *mem,
	uint8_t c,
	size_t len
) {
	uint8_t const *mem_byte = mem;

	size_t i = 0;
	while (i < len) {
		if (mem_byte[i] == c)
			return ((void *)(mem_byte + i));
		i++;
	}
	return (NULL);
}
