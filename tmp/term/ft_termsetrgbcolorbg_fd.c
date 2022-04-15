#include "ft/char.h"
#include "ft/num.h"
#include "ft/str.h"

#include "term.h"

bool ft_termsetrgbcolorbg_fd(t_color rgb, int fd) {
    if (ft_putstr_fd("\033[48;2;", fd) == false)
        return false;
    if (ft_putnum_fd(rgb.r, fd) == false)
        return false;
    if (ft_putchar_fd(';', fd) == false)
        return false;
    if (ft_putnum_fd(rgb.g, fd) == false)
        return false;
    if (ft_putchar_fd(';', fd) == false)
        return false;
    if (ft_putnum_fd(rgb.b, fd) == false)
        return false;
    return ft_putchar_fd('m', fd);
}
