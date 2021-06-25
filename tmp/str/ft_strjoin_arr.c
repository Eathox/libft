#include "ft/mem.h"

#include "str.h"

static size_t	totallen(const char **arr) {
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (arr[i] != NULL)
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len + 1);
}

static char		*joinstrs(char *str, const char **arr) {
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (arr[j] != NULL)
	{
		len = ft_strlen(arr[j]);
		ft_memcpy(&str[i], arr[j], len);
		i += len;
		j++;
	}
	return (str);
}

char			*ft_strjoin_arr(const char **arr) {
	char	*str;

	str = ft_strnew(totallen(arr));
	if (str == NULL)
		return (NULL);
	str = joinstrs(str, arr);
	return (str);
}
