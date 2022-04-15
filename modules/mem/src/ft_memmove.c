#include "../include/mem.h"

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
