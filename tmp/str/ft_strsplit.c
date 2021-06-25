#include "ft/char.h"

#include "str.h"

char		**ft_strsplit(const char *str, char c) {
	char	**arr;
	char	cs[2];

	cs[0] = c;
	cs[1] = '\0';
	arr = ft_strdsplit(str, cs);
	return (arr);
}
