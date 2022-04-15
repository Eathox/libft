#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../include/mem.h"
#include "types/include/types.h"

#define STEP 0x1
#define MAX CHAR_MAX

ParameterizedTestParameters(ft_memcpy, allign) {
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

ParameterizedTest(size_t *len, ft_memcpy, allign) {
    uint8_t result[*len];
    uint8_t expected[*len];
    void *return_ptr;

    bzero(result, *len);
    memset(expected, UCHAR_MAX, *len);

    return_ptr = ft_memcpy(result, expected, *len);
    cr_assert_arr_eq(result, expected, *len, "%zu", *len);
    cr_assert_eq(return_ptr, result, "Return pointer error");
}

Test(ft_memcpy, general) {
    size_t const step = STEP;
    uint8_t *result;
    uint8_t *expected;
    void *return_ptr;

    for (size_t len = 1; len < MAX; len += step) {
        result = calloc(len, sizeof(*result));
        expected = calloc(len, sizeof(*expected));

        cr_expect_neq(result, NULL);
        cr_expect_neq(expected, NULL);

        memset(expected, UCHAR_MAX, len);

        return_ptr = ft_memcpy(result, expected, len);
        cr_assert_arr_eq(result, expected, len, "%zu", len);
        cr_assert_eq(return_ptr, result, "Return pointer error");

        free(result);
        free(expected);
    }
}

Test(ft_memcpy, overlap) {
    size_t const len = 3;
    uint8_t result[] = {UCHAR_MAX, 0x0, UCHAR_MAX};
    uint8_t expected[] = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
    void *return_ptr;

    return_ptr = ft_memcpy(&result[1], &result, 2);
    cr_assert_arr_eq(result, expected, len);
    cr_assert_eq(return_ptr, &result[1], "Return pointer error");
}