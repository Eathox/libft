#include "ft/char.h"

#include "printf.h"
#include "priv.h"

int		ft_gettype(t_info *info, const char *str) {
	info->type = *str;
	if (ft_chrin(PF_A_TYPE_L, info->type))
	{
		info->type = ft_tolower(info->type);
		info->length = 'l';
	}
	return (-1);
}
