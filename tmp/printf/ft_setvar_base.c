#include "ft/char.h"

#include "printf.h"
#include "priv.h"

void	ft_setvar_base(t_info *info) {
	if (ft_chrin("diuf", info->type))
		info->var_base = 10;
	else if (ft_chrin("xXaA", info->type) || info->type == 'p')
		info->var_base = 16;
	else if (info->type == 'o')
		info->var_base = 8;
	else if (info->type == 'b')
		info->var_base = 2;
	else
		info->var_base = -1;
}
