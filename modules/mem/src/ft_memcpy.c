#include "../include/mem.h"
#include "types/include/types.h"

void *ft_memcpy(
    void *dst,
    const void *src,
    size_t len
) {
    uint8_t const *src_byte = src;
    uint8_t *dst_byte = dst;

    size_t i = 0;
    while (i < len) {
        dst_byte[i] = src_byte[i];
        i++;
    }
    return dst;
}
