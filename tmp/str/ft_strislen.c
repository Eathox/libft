#include "str.h"

size_t	ft_strislen(const char *str, bool (*f)(char)) {
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != '\0' && f(str[len]))
		len++;
	return (len);
}
