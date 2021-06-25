#include "ft/unum.h"

#include "printf.h"
#include "priv.h"

void	ft_addnum(t_info *info, intmax_t value) {
	intmax_t	num;

	num = (value < 0) ? -value : value;
	ft_addunum(info, num, ft_unumlen(num), 10);
}
