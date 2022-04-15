#include "ft/str.h"

#include "term.h"

bool ft_termresetcolorbg_fd(int fd) {
    return ft_putstr_fd("\033[49m\033[K", fd);
}
