#include <stdlib.h>

#include "mem.h"

/*
** * Frees the memory pointed to by *adr then sets *adr to NULL
** * If adr or *adr are NULL nothing happens
*/
void ft_memdel(
	void **adr
) {
	if (adr == NULL || *adr == NULL)
		return ;

	free(*adr);
	*adr = NULL;
}
