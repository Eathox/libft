#include "printf.h"
#include "priv.h"

void ft_addnstr(t_info *info, const char *str, size_t n) {
    if (n == 0)
        return;
    ft_addtobuff(info, str, n);
}
