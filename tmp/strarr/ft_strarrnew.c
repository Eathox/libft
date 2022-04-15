#include "ft/mem.h"

#include "strarr.h"

char **ft_strarrnew(size_t size) {
    char **arr;

    arr = (char **)ft_memalloc(sizeof(char *) * (size + 1));
    return arr;
}
