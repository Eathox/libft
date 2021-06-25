#include "ft/char.h"

#include "str.h"

size_t		ft_wrddcount(const char *str, const char *dlm) {
	t_uint64	bytes[2];
	size_t		count;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	count = 0;
	ft_chrsetbytes(bytes, dlm);
	while (str[i] != '\0')
	{
		if (ft_chrinbytes(bytes, str[i]))
			j = 0;
		else if (j == 0)
		{
			count++;
			j = 1;
		}
		i++;
	}
	return (count);
}
