#include "utf8.h"

bool ft_putnutf8str(const t_wchar *str, size_t n) {
    return ft_putnutf8str_fd(str, n, 1);
}
