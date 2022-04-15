#include "ft/char.h"
#include "ft/num.h"
#include "ft/str.h"

#include "term.h"

bool ft_termsetcolor_fd(t_uint8 color, int fd) {
    if (ft_putstr_fd("\033[38;5;", fd) == false)
        return false;
    if (ft_putnum_fd(color, fd) == false)
        return false;
    return ft_putchar_fd('m', fd);
}
