#include "utf8.h"

size_t	ft_utf8strlen(const t_wchar *str) {
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		len += ft_utf8len(str[i]);
		i++;
	}
	return (len);
}
