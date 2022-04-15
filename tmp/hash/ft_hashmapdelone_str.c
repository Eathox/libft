#include "ft/str.h"

#include "hash.h"

void ft_hashmapdelone_str(const t_hashmap *map, const char *key, void (*del)(void *)) {
    ft_hashmapdelone(map, key, ft_strlen(key) + 1, del);
}
