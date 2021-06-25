#include "ft/char.h"

#include "printf.h"
#include "priv.h"

static int	length(int c) {
	if (c == PF_DOUBLE_H)
		return (0);
	if (c == 'h')
		return (1);
	if (c == 'l' || c == 'j')
		return (2);
	if (c == 'L' || c == PF_DOUBLE_L || c == 'z')
		return (3);
	return (-1);
}

int			ft_getlength(t_info *info, const char *str) {
	if (ft_chrin(PF_A_LENGTH_D, info->length) && *str == info->length)
		info->length += *str;
	else if (length(*str) > length(info->length))
		info->length = *str;
	return (1);
}
