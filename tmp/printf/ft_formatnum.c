#include "ft/num.h"

#include "printf.h"
#include "priv.h"

void ft_formatnum(t_info *info) {
    intmax_t num;

    num = ft_overflowsigned(info);
    info->is_zero = (num == 0);
    info->is_negative = (num < 0);
    info->var_len = ft_numlen(num) - info->is_negative;
    ft_formatpad(info);
    if (info->precision == 0 && num == 0) {
        if (info->width != -1)
            ft_addnstr(info, " ", 1);
        return;
    }
    ft_addnum(info, num);
}
