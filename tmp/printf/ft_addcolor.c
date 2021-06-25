#include "printf.h"
#include "priv.h"

void	ft_addcolor(t_info *info, int color) {
	if (color < 0 || color > 255)
	{
		ft_addtobuff(info, "\033[39m\033[K", 8);
		return ;
	}
	ft_addtobuff(info, "\033[38;5;", 7);
	ft_addnum(info, color);
	ft_addtobuff(info, "m", 1);
}
