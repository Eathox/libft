#include "ft/char.h"

#include "hash.h"

size_t	ft_hashdjb2a_nocase(const void *key, size_t size) {
	const char	*str;
	size_t		hash;
	size_t		i;

	i = 0;
	hash = 5381;
	str = key;
	while (i < size)
	{
		hash = ft_tolower(str[i]) ^ (hash * 33);
		i++;
	}
	return (hash);
}
