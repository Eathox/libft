#include "str.h"

ssize_t		ft_strnindex(const char **arr, const char *str, size_t n) {
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (ft_strequ(str, arr[i]))
			return (i);
		i++;
	}
	return (-1);
}
