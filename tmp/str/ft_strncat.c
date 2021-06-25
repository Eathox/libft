#include "ft/mem.h"

#include "str.h"

char	*ft_strncat(char *str1, const char *str2, size_t n) {
	size_t	str1len;
	size_t	str2len;

	str1len = ft_strlen(str1);
	str2len = ft_strnlen(str2, n);
	ft_memcpy(&str1[str1len], str2, str2len);
	str1[(str1len + str2len)] = '\0';
	return (str1);
}
