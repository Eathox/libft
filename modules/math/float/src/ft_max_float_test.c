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

ParameterizedTestParameters(ft_max_float, general) {
    static params_t numbers[] = {
        {0.0, 1.0, 1.0},
        {1.0, 0.0, 1.0},
        {-0.0, 0.0, 0.0},
        {0.0, -0.0, 0.0},
    };

    size_t count = sizeof(numbers) / sizeof(*numbers);
    return cr_make_param_array(params_t, numbers, count);
}

ParameterizedTest(params_t *param, ft_max_float, general) {
    float128_t const num1 = param->num1;
    float128_t const num2 = param->num2;
    float128_t const expected = param->expected;

    float128_t result = ft_max_float(num1, num2);
    cr_assert_eq(result, expected, "%Lf, %Lf", num1, num2);
}

ParameterizedTestParameters(ft_max_float, nan_and_infinity) {
    static params_t numbers[] = {
        {0.0, NAN, 0},
        {NAN, 0.0, 0},
        {0.0, INFINITY, 0},
        {INFINITY, 0.0, 0},
    };

    size_t count = sizeof(numbers) / sizeof(*numbers);
    return cr_make_param_array(params_t, numbers, count);
}

ParameterizedTest(params_t *param, ft_max_float, nan_and_infinity, .signal = SIGABRT) {
    float128_t const num1 = param->num1;
    float128_t const num2 = param->num2;

    ft_max_float(num1, num2);
}
