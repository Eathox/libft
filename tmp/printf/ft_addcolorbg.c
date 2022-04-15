#include "printf.h"
#include "priv.h"

void ft_addcolorbg(t_info *info, int color) {
    if (color < 0 || color > 255) {
        ft_addtobuff(info, "\033[49m\033[K", 8);
        return;
    }
    ft_addtobuff(info, "\033[48;5;", 7);
    ft_addnum(info, color);
    ft_addtobuff(info, "m", 1);
}
