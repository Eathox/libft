#include "printf.h"
#include "priv.h"

void	ft_addwcharstr(t_info *info, const t_wchar *str, size_t n) {
	size_t	i;
	size_t	bytes;
	size_t	len;

	i = 0;
	len = 0;
	if (n == 0)
		return ;
	if (str == NULL)
	{
		ft_addnstr(info, "(null)", n);
		return ;
	}
	while (str[i] != '\0')
	{
		bytes = ft_utf8len(str[i]);
		if ((len + bytes) > n)
			return ;
		len += bytes;
		ft_addwchar(info, str[i]);
		i++;
	}
}
