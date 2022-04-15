#include "ft/str.h"

#include "strarr.h"

char **ft_strarrcpy(char **dst, const char **src) {
    size_t i;

    i = 0;
    while (src[i] != NULL) {
        dst[i] = ft_strdup(src[i]);
        if (dst[i] == NULL)
            return NULL;
        i++;
    }
    dst[i] = NULL;
    return dst;
}
