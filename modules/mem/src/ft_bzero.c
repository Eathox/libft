#include "../include/mem.h"

void *ft_bzero(
	void *mem,
	size_t len
) {
	ft_memset(mem, 0x0, len);
	return (mem);
}
