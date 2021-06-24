/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:37:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/18 19:37:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../types/types.h"
#include "mem.h"

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
	t_uint8 *result;
	t_uint8 expected[*len];

	memset(expected, UCHAR_MAX, *len);

	result = ft_memdup(expected, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);

	free(result);
}

Test(ft_memdup, general) {
	size_t const step = STEP;
	t_uint8 *result;
	t_uint8 *expected;

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
	t_uint8 *result;

	result = ft_memdup(NULL, len);
	cr_assert_eq(result, NULL);
}
