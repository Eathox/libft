#include "printf.h"
#include "priv.h"

bool	ft_isunsignint(const t_info *info) {
	if (info->var_type == U_INT || info->var_type == U_SHORT)
		return (true);
	if (info->var_type == MAX_U_INT || info->var_type == SIZE_T)
		return (true);
	if (info->var_type == U_LONG || info->var_type == U_LONG_LONG)
		return (true);
	if (info->var_type == U_CHAR_I || info->var_type == VOID)
		return (true);
	return (false);
}
