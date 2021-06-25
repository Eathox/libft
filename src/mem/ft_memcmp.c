#include "../types/types.h"
#include "mem.h"

/*
** * Compares len bytes of mem1 to mem2
** * Returns diffrance between first not equal byte or 0 if equal
*/
int ft_memcmp(
	void const *mem1,
	void const *mem2,
	size_t len
) {
	uint8_t const *mem1_byte = mem1;
	uint8_t const *mem2_byte = mem2;

	size_t i = 0;
	while (i < len) {
		if (mem1_byte[i] != mem2_byte[i])
			return (mem1_byte[i] - mem2_byte[i]);
		i++;
	}
	return (0);
}
