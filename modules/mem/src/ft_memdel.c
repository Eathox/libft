#include <stdlib.h>

#include "../include/mem.h"

void ft_memdel(
    void **adr
) {
    if (adr == NULL || *adr == NULL)
        return;

    free(*adr);
    *adr = NULL;
}
