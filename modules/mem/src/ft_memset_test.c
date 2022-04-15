#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../include/mem.h"
#include "types/include/types.h"

#define STEP 0x1
#define MAX CHAR_MAX

#define CHARACTER_SIZE (sizeof(uint8_t) * 1)
#define CHARACTER_MAX UCHAR_MAX
#define CHARACTER_STEP 0x1

ParameterizedTestParameters(ft_memset, allign) {
    static size_t lengths[] = {
        7,
        8,
        9,
        31,
        32,
        33,
        63,
        64,
        65,
    };

    size_t count = sizeof(lengths) / sizeof(*lengths);
    return cr_make_param_array(size_t, lengths, count);
}

ParameterizedTest(size_t *len, ft_memset, allign) {
    uint8_t const c = UCHAR_MAX;
    uint8_t *result = calloc(*len, sizeof(c));
    uint8_t *expected = calloc(*len, sizeof(c));
    void *return_ptr;

    cr_expect_neq(result, NULL);
    cr_expect_neq(expected, NULL);

    memset(expected, c, *len);
    return_ptr = ft_memset(result, c, *len);
    cr_assert_arr_eq(result, expected, *len, "%zu", *len);
    cr_assert_eq(return_ptr, result, "Return pointer error");

    free(result);
    free(expected);
}

Test(ft_memset, general) {
    size_t const step = STEP;
    uint8_t const c = UCHAR_MAX;
    uint8_t *result;
    uint8_t *expected;
    void *return_ptr;

    for (size_t len = 1; len < MAX; len += step) {
        result = calloc(len, sizeof(c));
        expected = calloc(len, sizeof(c));

        cr_expect_neq(result, NULL);
        cr_expect_neq(expected, NULL);

        memset(expected, c, len);
        return_ptr = ft_memset(result, c, len);
        cr_assert_arr_eq(result, expected, len, "%zu", len);
        cr_assert_eq(return_ptr, result, "Return pointer error");

        free(result);
        free(expected);
    }
}

Test(ft_memset, character) {
    size_t const step = CHARACTER_STEP;
    size_t const len = CHARACTER_SIZE;
    uint8_t result[CHARACTER_SIZE];
    uint8_t expected[CHARACTER_SIZE];
    void *return_ptr;

    for (uint8_t c = 0x0; c < CHARACTER_MAX; c += step) {
        memset(expected, c, len);
        return_ptr = ft_memset(result, c, len);
        cr_assert_arr_eq(result, expected, len, "%X", c);
        cr_assert_eq(return_ptr, result, "Return pointer error");
    }
}