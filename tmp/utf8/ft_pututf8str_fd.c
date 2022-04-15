#include "ft/str.h"

#include "utf8.h"

bool ft_pututf8str_fd(const t_wchar *str, int fd) {
    size_t i;

    i = 0;
    if (str == NULL)
        return ft_putstr_fd("(null)", fd);
    while (str[i] != '\0') {
        if (ft_pututf8_fd(str[i], fd) == false)
            return false;
        i++;
    }
    return true;
}
