#include "ft/char.h"
#include "ft/str.h"
#include "ft/num.h"

#include "numarr.h"

bool	ft_putnumarr(const intmax_t *arr, size_t len) {
	size_t	i;

	i = 0;
	if (arr == NULL)
		return (ft_putstr(NULL));
	while (i < len)
	{
		if (ft_putnum(arr[i]) == false)
			return (false);
		if (ft_putchar('\n') == false)
			return (false);
		i++;
	}
	return (true);
}
