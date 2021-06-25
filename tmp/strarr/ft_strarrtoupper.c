#include "ft/str.h"

#include "strarr.h"

void	ft_strarrtoupper(char **arr) {
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		ft_strtoupper(arr[i]);
		i++;
	}
}
