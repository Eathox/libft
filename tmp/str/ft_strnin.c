#include "ft/strarr.h"

#include "str.h"

bool ft_strnin(const char **arr, const char *str, size_t n) {
    size_t len;

    len = ft_strarrnlen(arr, n);
    return (ft_strnindex(arr, str, len + (len != n)) != -1);
}
