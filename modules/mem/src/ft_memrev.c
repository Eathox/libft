#include "types/include/types.h"
#include "mem.h"

void *ft_memrev(
	void *mem,
	size_t len
) {
	uint8_t *mem_byte = mem;
	uint8_t temp;

	size_t i = 0;
	while (i < (len / 2)) {
		temp = mem_byte[i];
		mem_byte[i] = mem_byte[(len - 1) - i];
		mem_byte[(len - 1) - i] = temp;
		i++;
	}
	return (mem);
}
