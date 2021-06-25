#include "ft/mem.h"

#include "str.h"

char	*ft_strnew(size_t size) {
	char	*str;

	str = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}
