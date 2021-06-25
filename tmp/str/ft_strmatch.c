#include "str.h"

bool	ft_strmatch(const char *str, const char *needle) {
	if (needle[0] == '\0' && str[0] == '\0')
		return (true);
	if (needle[0] != str[0] && needle[0] != '*')
		return (false);
	if (needle[0] == '*' && str[0] != '\0')
	{
		return (ft_strmatch(&str[1], &needle[1]) ||
				ft_strmatch(&str[1], &needle[0]) ||
				ft_strmatch(&str[0], &needle[1]));
	}
	return (ft_strmatch(&str[1], &needle[1]));
}
