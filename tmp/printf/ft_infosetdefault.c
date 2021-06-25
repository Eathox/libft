#include "printf.h"
#include "priv.h"

void	ft_infosetdefault(t_info *info) {
	info->length = -1;
	info->precision = -1;
	info->type = -1;
	info->width = -1;
	info->var_len = -1;
	info->var_type = -1;
	info->var_base = -1;
	info->padadded = 0;
	PF_FLAG_HASH = false;
	PF_FLAG_ZERO = false;
	PF_FLAG_MIN = false;
	PF_FLAG_PLUS = false;
	PF_FLAG_SPACE = false;
	PF_FLAG_APOST = false;
	info->is_zero = false;
	info->is_negative = false;
}
