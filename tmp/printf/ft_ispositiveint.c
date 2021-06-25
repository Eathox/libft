#include "printf.h"
#include "priv.h"

bool	ft_ispositiveint(const t_info *info) {
	return (ft_issignint(info) && info->is_negative == false);
}
