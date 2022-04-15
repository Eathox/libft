#include "ft/mem.h"
#include "ft/strarr.h"

#include "str.h"

char *ft_strjoin_var(size_t count, ...) {
    size_t i;
    char *str;
    char **arr;
    va_list args;

    i = 0;
    arr = (char **)ft_strarrnew(count);
    if (arr == NULL)
        return NULL;
    va_start(args, count);
    while (i < count) {
        arr[i] = va_arg(args, char *);
        i++;
    }
    va_end(args);
    str = ft_strjoin_arr((const char **)arr);
    ft_memdel((void **)&arr);
    return str;
}
