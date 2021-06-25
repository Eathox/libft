#include "ft/mem.h"

#include "str.h"

char	*ft_strchr(const char *str, char c) {
	return (ft_memchr(str, c, ft_strlen(str) + 1));
}
