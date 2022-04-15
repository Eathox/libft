#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../include/mem.h"
#include "types/include/types.h"

#define STEP 0x1
#define MAX CHAR_MAX

#define ALIGN_SIZE 128

ParameterizedTestParameters(ft_memccpy, allign) {
    static size_t indexes[] = {
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

    size_t count = sizeof(indexes) / sizeof(*indexes);
    return cr_make_param_array(size_t, indexes, count);
}

ParameterizedTest(size_t *index, ft_memccpy, allign) {
    uint8_t const c = 0x7F;
    size_t const size = ALIGN_SIZE;
    uint8_t result[ALIGN_SIZE];
    uint8_t expected[ALIGN_SIZE];
    void *return_ptr;

    bzero(result, size);
    bzero(expected, size);

    expected[*index - 1] = c;
    memset(expected, UCHAR_MAX, *index - 1);

    return_ptr = ft_memccpy(result, expected, c, size);
    cr_assert_arr_eq(result, expected, size, "%zu", *index);
    cr_assert_eq(return_ptr, &result[*index], "Return pointer error");
}

Test(ft_memccpy, general) {
    uint8_t const c = 0x7F;
    size_t const step = STEP;
    size_t const size = MAX;
    uint8_t *result = calloc(size, sizeof(*result));
    uint8_t *expected = calloc(size, sizeof(*expected));
    void *return_ptr;

    cr_expect_neq(result, NULL);
    cr_expect_neq(expected, NULL);

    for (size_t index = 1; index < size; index += step) {
        expected[index - 1] = c;
        memset(expected, UCHAR_MAX, index - 1);

        return_ptr = ft_memccpy(result, expected, c, size);
        cr_assert_arr_eq(result, expected, size, "%zu", index);
        cr_assert_eq(return_ptr, &result[index], "Return pointer error");

        bzero(expected, size);
        bzero(result, size);
    }

    free(result);
    free(expected);
}
