#include "ft/char.h"

#include "str.h"

bool		ft_strishex(const char *str) {
	size_t	len;

	len = ft_strislen(str, &ft_ishex);
	return (str[len] == '\0');
}
