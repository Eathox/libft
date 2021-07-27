#include "types/include/types.h"
#include "mem.h"

/*
** * Copy len amount of bytes in order of front to back from src to dst
** * This function does not handle memory area overlap use ft_memmove instead
** * Returns dst
*/
void *ft_memcpy(
	void *dst,
	const void *src,
	size_t len
) {
	uint8_t const *src_byte = src;
	uint8_t *dst_byte = dst;

	size_t i = 0;
	while (i < len) {
		dst_byte[i] = src_byte[i];
		i++;
	}
	return (dst);
}
