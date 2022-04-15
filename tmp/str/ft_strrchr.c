#include "ft/mem.h"

#include "str.h"

char *ft_strrchr(const char *str, char c) {
    return ft_memrchr(str, c, ft_strlen(str) + 1);
}
