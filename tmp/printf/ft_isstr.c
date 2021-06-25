#include "printf.h"
#include "priv.h"

bool		ft_isstr(const t_info *info) {
	return (info->var_type == STR || info->var_type == T_WCHAR_STR);
}
