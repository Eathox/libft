#include <stdlib.h>

#include "list.h"

void	ft_lstdelmem(void *content, size_t size) {
	(void)size;
	free(content);
}
