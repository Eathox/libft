#include "hash.h"

size_t ft_hashdjb2a(const void *key, size_t size) {
    const char *str;
    size_t hash;
    size_t i;

    i = 0;
    hash = 5381;
    str = key;
    while (i < size) {
        hash = str[i] ^ (hash * 33);
        i++;
    }
    return hash;
}
