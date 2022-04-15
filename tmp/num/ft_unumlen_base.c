#include "unum.h"

size_t ft_unumlen_base(uintmax_t value, int base) {
    size_t len;

    len = 0;
    if (base < 2 || base > 36)
        return 0;
    while (base != -1) {
        len++;
        value = value / base;
        if (value == 0)
            return len;
    }
    return len;
}
