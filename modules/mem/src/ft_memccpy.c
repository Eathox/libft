#include <string.h>

#include "types/include/types.h"
#include "../include/mem.h"

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
