#include "ft/mem.h"

#include "str.h"

char	*ft_strncpy(char *dst, const char *src, size_t n) {
	size_t	dstlen;

	dstlen = ft_strnlen(src, n);
	ft_memcpy(dst, src, dstlen);
	ft_bzero(&dst[dstlen], n - dstlen);
	return (dst);
}
