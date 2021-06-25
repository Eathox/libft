#include "ft/strarr.h"
#include "ft/mem.h"

#include "str.h"

char		**ft_strfldnew(size_t x, size_t y, char c) {
	char	**arr;
	size_t	i;

	i = 0;
	arr = ft_strarrnew(y);
	if (arr == NULL)
		return (NULL);
	while (i < y)
	{
		arr[i] = ft_strnew(x);
		if (arr[i] == NULL)
		{
			ft_strarrdel(&arr);
			return (NULL);
		}
		ft_memset(arr[i], c, x);
		i++;
	}
	return (arr);
}
