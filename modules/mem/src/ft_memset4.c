#include "../include/mem.h"

void *ft_memset4(
    void *mem,
    uint32_t c,
    size_t len
) {
    uint32_t *mem_byte_4 = mem;

    size_t i = 0;
    while (i < len) {
        mem_byte_4[i] = c;
        i++;
    }
    return mem;
}
