#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>

#include "../include/mem.h"
#include "types/include/types.h"

#define STEP 0x1
#define MAX ((STEP * 20) + 1)

#define CHARACTER_SIZE (sizeof(uint8_t) * 1)
#define CHARACTER_MAX UCHAR_MAX
#define CHARACTER_STEP 0x1

Test(ft_memrchr, general) {
    size_t const step = STEP;
    size_t const size = MAX;
    uint8_t *mem_byte = calloc(size, sizeof(*mem_byte));
    uint8_t *result;

    for (size_t index = 1; index < size; index += step) {
        cr_expect_neq(mem_byte, NULL);

        mem_byte[index - 0] = UCHAR_MAX;
        mem_byte[index - 1] = UCHAR_MAX;

        result = ft_memrchr(mem_byte, UCHAR_MAX, size);
        cr_assert_eq((size_t)index, (size_t)(result - mem_byte), "%zu", index);

        bzero(mem_byte, size);
    }
    free(mem_byte);
}

Test(ft_memrchr, character) {
    size_t const step = CHARACTER_STEP;
    size_t const len = CHARACTER_SIZE;
    uint8_t mem_byte[CHARACTER_SIZE];
    uint8_t *result;

    for (uint8_t c = 0x0; c < CHARACTER_MAX; c += step) {
        mem_byte[len - 1] = c;

        result = ft_memrchr(mem_byte, c, len);
        cr_assert_eq((size_t)(len - 1), (size_t)(result - mem_byte), "%02X", c);
    }
}

Test(ft_memrchr, not_found) {
    size_t const len = CHARACTER_SIZE;
    uint8_t mem_byte[CHARACTER_SIZE];
    uint8_t *result;

    result = ft_memrchr(mem_byte, UCHAR_MAX, len);
    cr_assert_eq(result, NULL);
}
