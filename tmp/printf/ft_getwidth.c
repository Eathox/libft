#include "ft/char.h"
#include "ft/num.h"

#include "printf.h"
#include "priv.h"

size_t ft_getwidth(t_info *info, const char *str) {
    size_t i;

    i = 1;
    if (*str == '*') {
        info->width = va_arg(info->args, int);
        if (info->width < 0) {
            PF_FLAG_MIN = true;
            info->width = -info->width;
        }
        return 1;
    }
    info->width = ft_atoi(str);
    while (ft_isdigit(str[i]))
        i++;
    return i;
}
