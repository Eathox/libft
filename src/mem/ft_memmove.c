#include "mem.h"

/*
** * Copy len amount of bytes from src to dst memory area overlap is handled
** * Returns dst
*/
void *ft_memmove(
	void *dst,
	void const *src,
	size_t len
) {
	if ((size_t)src < (size_t)dst)
		ft_memrcpy(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
