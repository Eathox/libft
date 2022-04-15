#include "ft/char.h"
#include "ft/num.h"

#include "printf.h"
#include "priv.h"

size_t ft_getprecision(t_info *info, const char *str) {
    size_t i;

    i = 1;
    if (str[1] == '*') {
        info->precision = va_arg(info->args, int);
        if (info->precision < 0)
            info->precision = -1;
        return 2;
    }
    info->precision = ft_atoi(&str[i]);
    while (ft_isdigit(str[i]))
        i++;
    return i;
}
