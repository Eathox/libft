#include <math.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../include/float.h"
#include "types/include/types.h"

typedef struct params_s {
    float128_t num1;
    float128_t num2;
    float128_t expected;
} params_t;

ParameterizedTestParameters(ft_min_float, general) {
    static params_t numbers[] = {
        {0.0, 1.0, 0.0},
        {1.0, 0.0, 0.0},
        {0.0, 0.0, 0.0},
        {0.0, -0.0, -0.0},
    };

    size_t count = sizeof(numbers) / sizeof(*numbers);
    return cr_make_param_array(params_t, numbers, count);
}

ParameterizedTest(params_t *param, ft_min_float, general) {
    float128_t const num1 = param->num1;
    float128_t const num2 = param->num2;
    float128_t const expected = param->expected;

    float128_t result = ft_min_float(num1, num2);
    cr_assert_eq(result, expected, "%Lf, %Lf", num1, num2);
}

Test(ft_min_float, infinity) {
    float128_t const num = 42;
    float128_t const expected = num;
    float128_t result;

    result = ft_min_float(num, INFINITY);
    cr_assert_eq(result, expected);

    result = ft_min_float(INFINITY, num);
    cr_assert_eq(result, expected);
}

Test(ft_min_float, nan) {
    float128_t const num = 42;
    float128_t const expected = num;
    float128_t result;

    result = ft_min_float(num, NAN);
    cr_assert_eq(result, expected);

    result = ft_min_float(NAN, num);
    cr_assert_eq(result, expected);
}
