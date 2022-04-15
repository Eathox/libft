#include "hash.h"
#include "priv.h"

void *ft_hashmapget(const t_hashmap *map, const void *key, size_t keysize) {
    t_hashlist *current;
    size_t index;

    index = map->f(key, keysize) % map->size;
    current = map->arr[index];
    while (current != NULL && ft_keyequ(current, key, keysize) == false)
        current = current->next;
    if (current == NULL)
        return NULL;
    return current->value;
}
