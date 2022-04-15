#include "printf.h"
#include "priv.h"

void ft_formatchar(t_info *info) {
    t_wchar c;

    if (info->var_type == T_WCHAR || info->type == 'c')
        c = va_arg(info->args, t_wchar);
    else
        c = '%';
    info->var_len = ft_utf8len(c);
    ft_formatpad(info);
    if (info->var_type == T_WCHAR)
        ft_addwchar(info, c);
    else if (info->type == '%')
        ft_addnstr(info, "%", 1);
    else if (info->type == 'c')
        ft_addchar(info, (char)c);
}
