#include "strarr.h"

size_t	ft_strarrlen(const char **arr) {
	size_t	len;

	len = 0;
	if (arr == NULL)
		return (0);
	while (arr[len] != NULL)
		len++;
	return (len);
}
