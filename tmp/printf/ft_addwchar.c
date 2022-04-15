#include "printf.h"
#include "priv.h"

void ft_addwchar(t_info *info, t_wchar c) {
    t_wchar bit;
    size_t i;
    size_t len;

    i = 1;
    len = ft_utf8len(c);
    bit = (0x80 | c) & 0x7f;
    if (len == 2)
        bit = (0xe0 | (c >> 6)) & 0xdf;
    else if (len == 3)
        bit = (0xf0 | (c >> 12)) & 0xef;
    else if (len == 4)
        bit = (0xf8 | (c >> 18)) & 0xf7;
    ft_addtobuff(info, (char *)&bit, 1);
    while (i < len) {
        i++;
        bit = (0xc0 | (c >> (6 * (len - i)))) & 0xbf;
        ft_addtobuff(info, (char *)&bit, 1);
    }
}
