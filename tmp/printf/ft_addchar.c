#include "printf.h"
#include "priv.h"

void ft_addchar(t_info *info, char c) {
    ft_addtobuff(info, &c, 1);
}
