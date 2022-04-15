#include "ft/mem.h"

#include "str.h"

int ft_strncmp(const char *str1, const char *str2, size_t n) {
    size_t len;

    len = ft_strnlen(str1, n);
    return ft_memcmp(str1, str2, len + (len != n));
}
