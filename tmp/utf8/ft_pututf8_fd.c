#include "ft/char.h"

#include "utf8.h"

bool ft_pututf8_fd(t_wchar c, int fd) {
    t_wchar bit;
    size_t i;
    size_t len;

    i = 1;
    len = ft_utf8len(c);
    if (len == 1)
        bit = (0x80 | c) & 0x7f;
    else if (len == 2)
        bit = (0xe0 | (c >> 6)) & 0xdf;
    else if (len == 3)
        bit = (0xf0 | (c >> 12)) & 0xef;
    else
        bit = (0xf8 | (c >> 18)) & 0xf7;
    if (ft_putchar_fd(bit, fd) == false)
        return false;
    while (i < len) {
        i++;
        bit = (0xc0 | (c >> (6 * (len - i)))) & 0xbf;
        if (ft_putchar_fd(bit, fd) == false)
            return false;
    }
    return true;
}
