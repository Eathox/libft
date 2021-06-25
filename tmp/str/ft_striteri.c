#include "str.h"

void	ft_striteri(const char *str, void (*f)(size_t, const char *)) {
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		i++;
	}
}
