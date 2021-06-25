#include "printf.h"
#include "priv.h"

bool	ft_iszeropad(const t_info *info) {
	if (info->precision != -1 && info->var_len != 0 &&
		info->var_len >= info->precision)
		return (false);
	return (PF_FLAG_ZERO || (info->precision != -1 && ft_isstr(info) == false));
}
