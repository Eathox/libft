#include "types/include/types.h"
#include "../include/mem.h"

void *ft_memrcpy(
	void *dst,
	void const *src,
	size_t len
) {
	uint8_t const *src_byte = src;
	uint8_t *dst_byte = dst;

	size_t i = len;
	while (i > 0) {
		i--;
		dst_byte[i] = src_byte[i];
	}
	return (dst);
}
