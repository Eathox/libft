#include "ft/str.h"

#include "utf8.h"

bool	ft_putnutf8str_fd(const t_wchar *str, size_t n, int fd) {
	size_t	i;
	size_t	bytes;
	size_t	len;

	i = 0;
	len = 0;
	if (str == NULL)
		return (ft_putnstr_fd("(null)", n, fd));
	while (str[i] != '\0')
	{
		bytes = ft_utf8len(str[i]);
		if ((len + bytes) > n)
			return (true);
		len += bytes;
		if (ft_pututf8_fd(str[i], fd) == false)
			return (false);
		i++;
	}
	return (true);
}
