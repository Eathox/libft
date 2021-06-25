#include "str.h"

bool	ft_strnequ_nocase(const char *str1, const char *str2, size_t n) {
	return (ft_strncmp_nocase(str1, str2, n) == 0);
}
