#include "ft/str.h"

#include "hash.h"

void *ft_hashmapget_str(const t_hashmap *map, const char *key) {
    return ft_hashmapget(map, key, ft_strlen(key) + 1);
}
