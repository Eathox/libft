#include "str.h"

char	*ft_strmap(const char *str, char (*f)(char)) {
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = ft_strlen(str);
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = f(str[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
