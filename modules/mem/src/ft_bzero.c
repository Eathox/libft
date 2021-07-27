#include "mem.h"

/*
** * Sets len amount of bytes in mem to the value 0x0
** * Returns mem
*/
void *ft_bzero(
	void *mem,
	size_t len
) {
	ft_memset(mem, 0x0, len);
	return (mem);
}
