#include "str.h"

char *ft_strmapi(const char *str, char (*f)(size_t, char)) {
    size_t i;
    size_t len;
    char *ret;

    i = 0;
    len = ft_strlen(str);
    ret = ft_strnew(len);
    if (ret == NULL)
        return NULL;
    while (i < len) {
        ret[i] = f(i, str[i]);
        i++;
    }
    ret[i] = '\0';
    return ret;
}
