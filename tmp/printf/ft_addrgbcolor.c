#include "printf.h"
#include "priv.h"

void	ft_addrgbcolor(t_info *info, t_uint8 r, t_uint8 g, t_uint8 b) {
	ft_addtobuff(info, "\033[38;2;", 7);
	ft_addnum(info, r);
	ft_addtobuff(info, ";", 1);
	ft_addnum(info, g);
	ft_addtobuff(info, ";", 1);
	ft_addnum(info, b);
	ft_addtobuff(info, "m", 1);
}
