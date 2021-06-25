#include "str.h"

ssize_t		ft_strindex(const char **arr, const char *str) {
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (ft_strequ(str, arr[i]))
			return (i);
		i++;
	}
	return (-1);
}
