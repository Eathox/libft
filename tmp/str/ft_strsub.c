#include "ft/mem.h"

#include "str.h"

char *ft_strsub(const char *str, size_t start, size_t len) {
    char *ret;

    ret = ft_strnew(len);
    if (ret == NULL)
        return NULL;
    ft_memcpy(ret, &str[start], len);
    ret[len] = '\0';
    return ret;
}
