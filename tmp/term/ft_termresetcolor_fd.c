#include "ft/str.h"

#include "term.h"

bool ft_termresetcolor_fd(int fd) {
    return ft_putstr_fd("\033[39m\033[K", fd);
}
