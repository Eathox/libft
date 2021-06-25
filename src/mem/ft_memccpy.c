#include <string.h>

#include "../types/types.h"
#include "mem.h"

/*
** * Copy at most len amount of bytes in order of front to back from src to dst
** * Stoping when c is found in src
** * This function does not handle memory area overlap
** * Returns a pointer to the next byte in dst after c or NULL if c wasent found
*/
void *ft_memccpy(
	void *dst,
	void const *src,
	uint8_t c,
	size_t len
) {
	uint8_t const *src_byte = src;
	uint8_t *dst_byte = dst;

	size_t i = 0;
	while (i < len) {
		dst_byte[i] = src_byte[i];
		if (src_byte[i] == c)
			return (&dst_byte[i + 1]);
		i++;
	}
	return (NULL);
}
