#include "utf8.h"

size_t	ft_utf8strnlen(const t_wchar *str, size_t n) {
	size_t	i;
	size_t	bytes;
	size_t	len;

	i = 0;
	len = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		bytes = ft_utf8len(str[i]);
		if ((len + bytes) > n)
			return (len);
		len += bytes;
		i++;
	}
	return (len);
}
