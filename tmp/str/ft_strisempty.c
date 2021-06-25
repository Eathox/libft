#include "ft/char.h"

#include "str.h"

bool		ft_strisempty(const char *str) {
	size_t	len;

	len = ft_strislen(str, &ft_isspace);
	return (str[len] == '\0');
}
