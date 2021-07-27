#include <string.h>

#include "types/include/types.h"
#include "mem.h"

/*
** * Searches len amount of bytes in mem for the last instance of c
** * Returns NULL if no instacne of c was found
*/
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
