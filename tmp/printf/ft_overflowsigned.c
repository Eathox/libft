#include "printf.h"
#include "priv.h"

intmax_t ft_overflowsigned(t_info *info) {
    if (info->var_type == LONG)
        return va_arg(info->args, long);
    if (info->var_type == LONG_LONG)
        return va_arg(info->args, long long);
    if (info->var_type == MAX_INT)
        return va_arg(info->args, intmax_t);
    if (info->var_type == CHAR_I)
        return (char)va_arg(info->args, int);
    if (info->var_type == SHORT)
        return (short)va_arg(info->args, int);
    return va_arg(info->args, int);
}
