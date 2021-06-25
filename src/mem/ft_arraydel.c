#include <stdlib.h>

#include "mem.h"

static void free_members(
	void **array,
	void (*del)(void**)
) {
	size_t i = 0;
	while (array[i] != NULL) {
		del(&array[i]);
		i++;
	}
}

/*
** * Frees NULL terminated array and all its members using the function del
** * If the function del is NULL only the array is deleted
*/
void ft_arraydel(
	void ***array,
	void (*del)(void**)
) {
	if (array == NULL || *array == NULL)
		return ;

	if (del != NULL)
		free_members(*array, del);
	ft_memdel((void**)array);
}
