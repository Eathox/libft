#include "ft/str.h"

#include "term.h"

bool ft_termclr_fd(int fd) {
    return ft_putstr_fd("\033[1;1H\033[2J\n", fd);
}
