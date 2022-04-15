#include "str.h"

bool ft_putstr(const char *str) {
    return ft_putstr_fd(str, 1);
}
