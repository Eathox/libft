#include "str.h"

bool	ft_strnequ(const char *str1, const char *str2, size_t n) {
	return (ft_strncmp(str1, str2, n) == 0);
}
