#include "ft/mem.h"

#include "hash.h"
#include "priv.h"

static t_hashlist *newlst(const void *key, size_t keysize, void *value) {
    void *key_dup;
    t_hashlist *new;

    key_dup = ft_memdup(key, keysize);
    if (key_dup == NULL)
        return NULL;
    new = (t_hashlist *)ft_memalloc(sizeof(t_hashlist));
    if (new == NULL) {
        ft_memdel(&key_dup);
        return NULL;
    }
    new->key = key_dup;
    new->value = value;
    new->keysize = keysize;
    return new;
}

bool ft_hashmapadd(const t_hashmap *map, const void *key, size_t keysize, void *value) {
    t_hashlist *current;
    size_t index;

    index = map->f(key, keysize) % map->size;
    current = map->arr[index];
    if (current == NULL) {
        map->arr[index] = newlst(key, keysize, value);
        return (map->arr[index] != NULL);
    }
    while (current->next != NULL && ft_keyequ(current, key, keysize) == false)
        current = current->next;
    if (ft_keyequ(current, key, keysize) == true) {
        current->value = value;
        return true;
    }
    current->next = newlst(key, keysize, value);
    return (current->next != NULL);
}
