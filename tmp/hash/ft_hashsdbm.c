#include "hash.h"

size_t	ft_hashsdbm(const void *key, size_t size) {
	const char	*str;
	size_t		hash;
	size_t		i;

	i = 0;
	hash = 0;
	str = key;
	while (i < size)
	{
		hash = str[i] + (hash << 6) + (hash << 16) - hash;
		i++;
	}
	return (hash);
}
