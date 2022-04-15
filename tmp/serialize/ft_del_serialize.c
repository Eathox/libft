#include "ft/mem.h"

#include "serialize.h"

void *ft_del_serialize(t_serialize **serialize) {
    if (serialize == NULL || *serialize == NULL)
        return NULL;
    ft_memdel((void **)&(*serialize)->content);
    ft_memdel((void **)serialize);
    return NULL;
}
