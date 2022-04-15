#include "ft/mem.h"

#include "hash.h"
#include "priv.h"

bool ft_keyequ(const t_hashlist *entry, const void *key, size_t keysize) {
    if (entry->keysize != keysize)
        return false;
    return ft_memequ(entry->key, key, keysize);
}
