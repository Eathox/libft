#include "ft/mem.h"

#include "str.h"

int		ft_strcmp(const char *str1, const char *str2) {
	return (ft_memcmp(str1, str2, ft_strlen(str1) + 1));
}
