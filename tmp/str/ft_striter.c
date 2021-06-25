#include "str.h"

void	ft_striter(const char *str, void (*f)(const char *)) {
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		f(&str[i]);
		i++;
	}
}
