#include "types/include/types.h"
#include "mem.h"

/*
** * Copy len amount of bytes in order of back to front from src to dst
** * This function does not handle memory area overlap use ft_memmove instead
** * Returns dst
*/
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
