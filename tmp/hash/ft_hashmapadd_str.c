#include "ft/str.h"

#include "hash.h"

bool ft_hashmapadd_str(const t_hashmap *map, const char *key, void *value) {
    return ft_hashmapadd(map, key, ft_strlen(key) + 1, value);
}
