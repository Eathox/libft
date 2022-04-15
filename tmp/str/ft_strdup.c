#include "ft/mem.h"

#include "str.h"

char *ft_strdup(const char *str) {
    size_t len;
    char *dup;

    len = ft_strlen(str);
    dup = ft_strnew(len);
    if (dup == NULL)
        return NULL;
    ft_memcpy(dup, str, len);
    return dup;
}
