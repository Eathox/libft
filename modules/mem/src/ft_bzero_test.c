#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "types/include/types.h"
#include "../include/mem.h"

#define STEP 0x1
#define MAX CHAR_MAX

ParameterizedTestParameters(ft_bzero, allign) {
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

ParameterizedTest(size_t *len, ft_bzero, allign) {
	uint32_t result[*len];
	uint8_t expected[*len];
	void *return_ptr;

	bzero(expected, *len);
	return_ptr = ft_bzero(result, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}

Test(ft_bzero, general) {
	size_t const step = STEP;
	uint8_t *result;
	uint8_t *expected;
	void *return_ptr;

	for (size_t len = 1; len < MAX; len += step) {
		result = calloc(len, sizeof(uint8_t));
		expected = calloc(len, sizeof(uint8_t));

		cr_expect_neq(result, NULL);
		cr_expect_neq(expected, NULL);

		bzero(expected, len);
		return_ptr = ft_bzero(result, len);
		cr_assert_arr_eq(result, expected, len, "%zu", len);
		cr_assert_eq(return_ptr, result, "Return pointer error");

		free(result);
		free(expected);
	}
}
