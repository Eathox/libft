#include "strarr.h"

char	**ft_strarrdup(const char **arr) {
	char	**dup;

	dup = ft_strarrnew(ft_strarrlen(arr));
	if (dup == NULL)
		return (NULL);
	if (ft_strarrcpy(dup, arr) == NULL)
	{
		ft_strarrdel(&dup);
		return (NULL);
	}
	return (dup);
}
