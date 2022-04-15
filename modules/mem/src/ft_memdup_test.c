#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../include/mem.h"
#include "types/include/types.h"

#define STEP 0x1
#define MAX CHAR_MAX

ParameterizedTestParameters(ft_memdup, allign) {
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

ParameterizedTest(size_t *len, ft_memdup, allign) {
    uint8_t *result;
    uint8_t expected[*len];

    memset(expected, UCHAR_MAX, *len);

    result = ft_memdup(expected, *len);
    cr_assert_arr_eq(result, expected, *len, "%zu", *len);

    free(result);
}

Test(ft_memdup, general) {
    size_t const step = STEP;
    uint8_t *result;
    uint8_t *expected;

    for (size_t len = 1; len < MAX; len += step) {
        expected = calloc(len, sizeof(*expected));
        cr_expect_neq(expected, NULL);

        memset(expected, UCHAR_MAX, len);

        result = ft_memdup(expected, len);
        cr_assert_arr_eq(result, expected, len, "%zu", len);

        free(result);
        free(expected);
    }
}

Test(ft_memdup, zero) {
    size_t const len = 0;
    uint8_t *result;

    result = ft_memdup(NULL, len);
    cr_assert_eq(result, NULL);
}