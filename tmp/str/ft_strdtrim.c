#include "ft/char.h"

#include "str.h"

char *ft_strdtrim(const char *str, const char *dlm) {
    char *ret;
    t_uint64 bytes[2];
    size_t len;
    size_t i;

    i = 0;
    len = ft_strlen(str);
    ft_chrsetbytes(bytes, dlm);
    while (ft_chrinbytes(bytes, str[i]) && str[i] != '\0')
        i++;
    if (i == len)
        return ft_strnew(0);
    while (ft_chrinbytes(bytes, str[(len - 1)]) && (len - 1) > i)
        len--;
    ret = ft_strndup(&str[i], (size_t)(len - i));
    return ret;
}
