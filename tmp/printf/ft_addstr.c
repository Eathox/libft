#include "ft/str.h"

#include "printf.h"
#include "priv.h"

size_t		ft_addstr(t_info *info, const char *str) {
	size_t	len;

	if (str != NULL)
	{
		len = ft_strdlen(str, "%");
		ft_addnstr(info, str, len);
	}
	else
	{
		len = 6;
		ft_addnstr(info, "(null)", len);
	}
	return ((len > 0) ? len - 1 : len);
}
