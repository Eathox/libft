#include <string.h>

#include "mem.h"

/*
** * Searches len amount of bytes in mem for the first instance of needle
** * Returns mem if needle_len is 0 and NULL if no instance of needle was found
*/
void *ft_memmem(
	void const *mem,
	size_t mem_len,
	void const *needle,
	size_t needle_len
) {
	uint8_t const *mem_byte = mem;
	uint8_t const *needle_byte = needle;

	if (needle_len == 0)
		return ((void *)mem_byte);

	size_t i = 0;
	while (i < mem_len) {
		if ((mem_len - i) < needle_len)
			return (NULL);
		if (ft_memcmp(mem_byte + i, needle_byte, needle_len) == 0)
			return ((void *)(mem_byte + i));
		i++;
	}
	return (NULL);
}
