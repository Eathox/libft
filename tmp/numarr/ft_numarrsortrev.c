#include "numarr.h"

void	ft_numarrsortrev(intmax_t *arr,
	bool (*f)(intmax_t, intmax_t), size_t len)
	{
	size_t		i;
	size_t		j;
	intmax_t	current;

	i = 1;
	while (i < len)
	{
		j = i;
		current = arr[i];
		while (j > 0 && f(current, arr[j - 1]) == false)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
