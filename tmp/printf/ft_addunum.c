#include "printf.h"
#include "priv.h"

void	ft_addunum(t_info *info, uintmax_t value, size_t len, int base) {
	char	c;

	if (len == 0)
		return ;
	if (len > 1)
		ft_addunum(info, value / base, len - 1, base);
	c = value % base;
	if (c <= 9)
		c += '0';
	else if (c > 9 && info->type != 'X')
		c += 'a' - 10;
	else
		c += 'A' - 10;
	ft_addtobuff(info, &c, 1);
}
