#include "str.h"

char	*ft_strndup(const char *str, size_t n) {
	size_t	len;
	char	*dup;

	len = ft_strnlen(str, n);
	dup = ft_strnew(len);
	if (dup == NULL)
		return (NULL);
	ft_strncpy(dup, str, len);
	return (dup);
}
