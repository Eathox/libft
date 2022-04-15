#include "ft/str.h"

#include "strarr.h"

char **ft_strarrcpy_var(char **dst, size_t count, ...) {
    size_t i;
    va_list args;

    i = 0;
    va_start(args, count);
    while (i < count) {
        dst[i] = ft_strdup(va_arg(args, char *));
        if (dst[i] == NULL) {
            va_end(args);
            return NULL;
        }
        i++;
    }
    va_end(args);
    return dst;
}
