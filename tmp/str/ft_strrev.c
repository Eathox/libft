#include "ft/mem.h"

#include "str.h"

void ft_strrev(char *str) {
    ft_memrev(str, ft_strlen(str));
}
