#include "str.h"

bool ft_putnstr(const char *str, size_t n) {
    return ft_putnstr_fd(str, n, 1);
}
