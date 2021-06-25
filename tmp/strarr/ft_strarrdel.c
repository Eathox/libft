#include "ft/str.h"

#include "strarr.h"

void	ft_strarrdel(char ***arr) {
	size_t	i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while ((*arr)[i] != NULL)
	{
		ft_strdel(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
