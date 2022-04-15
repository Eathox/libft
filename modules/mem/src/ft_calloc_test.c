#include <string.h>
#include <limits.h>
#include <stdint.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "types/include/types.h"
#include "../include/mem.h"

#define FILL_MEMORY_COUNT 16
#define FILL_MEMORY_SIZE 24

static void fill_memory(void) {
	uint8_t *holder[FILL_MEMORY_COUNT];

	for (size_t i = 0; i < FILL_MEMORY_COUNT; i++) {
		holder[i] = malloc(FILL_MEMORY_SIZE);
		cr_expect_neq(holder[i], NULL);

		memset(holder[i], UCHAR_MAX, FILL_MEMORY_SIZE);
	}

	for (size_t i = 0; i < FILL_MEMORY_COUNT; i++)
		free(holder[i]);
}

typedef struct params_s {
	size_t size;
	size_t count;
} params_t;

ParameterizedTestParameters(ft_calloc, general) {
	static params_t size_count[] = {
		{1, 1},
		{8, 1},
		{1, 8},
		{8, 8},
		{3, 3},
	};

	size_t count = sizeof(size_count) / sizeof(*size_count);
	return cr_make_param_array(params_t, size_count, count);
}

ParameterizedTest(params_t *param, ft_calloc, general, .init = fill_memory) {
	size_t const size = param->size;
	size_t const count = param->count;
	uint8_t *result;
	uint8_t expected[size * count];

	result = ft_calloc(count, size);
	cr_expect_neq(result, NULL);

	bzero(expected, (size * count));
	cr_assert_arr_eq(result, expected, sizeof(expected), "%zu, %zu", size, count);

	free(result);
}

ParameterizedTestParameters(ft_calloc, zero) {
	static params_t size_count[] = {
		{0, 1},
		{1, 0},
		{0, 0},
	};

	size_t count = sizeof(size_count) / sizeof(*size_count);
	return cr_make_param_array(params_t, size_count, count);
}

ParameterizedTest(params_t *param, ft_calloc, zero) {
	size_t const size = param->size;
	size_t const count = param->count;
	uint8_t *result;

	result = ft_calloc(count, size);
	cr_assert_eq(result, NULL, "%zu, %zu", size, count);
}

Test(ft_calloc, overflow) {
	size_t const size = SIZE_MAX;
	size_t const count = 2;
	uint8_t *result;

	result = ft_calloc(count, size);
	cr_assert_eq(result, NULL);
}
