#include "strarr.h"

size_t ft_strarrnlen(const char **arr, size_t n) {
    size_t len;

    len = 0;
    if (arr == NULL)
        return 0;
    while (len < n && arr[len] != NULL)
        len++;
    return len;
}
