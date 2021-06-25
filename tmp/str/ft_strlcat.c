#include "ft/mem.h"

#include "str.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size) {
	size_t	dstlen;
	size_t	srclen;

	srclen = 0;
	if (size == 0)
		return (ft_strlen(src));
	dstlen = ft_strnlen(dst, size);
	while (src[srclen] != '\0' && (dstlen + srclen) < (size - 1))
		srclen++;
	ft_memcpy(&dst[dstlen], src, srclen);
	if ((dstlen + srclen) != size)
		dst[(dstlen + srclen)] = '\0';
	return (dstlen + srclen + ft_strlen(&src[srclen]));
}
