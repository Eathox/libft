#include <math.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../include/float.h"
#include "types/include/types.h"

ParameterizedTestParameters(ft_sign_float, positive) {
    static float128_t numbers[] = {
        0.0,
        0.1,
        1.0,
        4.2};

    size_t count = sizeof(numbers) / sizeof(*numbers);
    return cr_make_param_array(float128_t, numbers, count);
}

ParameterizedTest(float128_t *num, ft_sign_float, positive) {
    float128_t const expected = 1.0;
    float128_t result = ft_sign_float(*num);

    cr_assert_eq(result, expected, "%Lf", *num);
}

ParameterizedTestParameters(ft_sign_float, negative) {
    static float128_t numbers[] = {
        -0.0,
        -0.1,
        -1.0,
        -4.2};

    size_t count = sizeof(numbers) / sizeof(*numbers);
    return cr_make_param_array(float128_t, numbers, count);
}

ParameterizedTest(float128_t *num, ft_sign_float, negative) {
    float128_t const expected = -1.0;
    float128_t result = ft_sign_float(*num);

    cr_assert_eq(result, expected, "%Lf", *num);
}

Test(ft_sign_float, infinity, .signal = SIGABRT) {
    ft_sign_float(INFINITY);
}

Test(ft_sign_float, nan, .signal = SIGABRT) {
    ft_sign_float(NAN);
}
