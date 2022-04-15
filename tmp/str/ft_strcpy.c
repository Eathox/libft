#include "ft/mem.h"

#include "str.h"

char *ft_strcpy(char *dst, const char *src) {
    size_t len;

    len = ft_strlen(src);
    ft_memcpy(dst, src, len);
    dst[len] = '\0';
    return dst;
}
