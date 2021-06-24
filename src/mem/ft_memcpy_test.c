/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy_test.c                                   :+:    :+:            */
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
	t_uint8 result[*len];
	t_uint8 expected[*len];
	void *return_ptr;

	bzero(result, *len);
	memset(expected, UCHAR_MAX, *len);

	return_ptr = ft_memcpy(result, expected, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}

Test(ft_memcpy, general) {
	size_t const step = STEP;
	t_uint8 *result;
	t_uint8 *expected;
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
	t_uint8 result[] = {UCHAR_MAX, 0x0, UCHAR_MAX};
	t_uint8 expected[] = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
	void *return_ptr;

	return_ptr = ft_memcpy(&result[1], &result, 2);
	cr_assert_arr_eq(result, expected, len);
	cr_assert_eq(return_ptr, &result[1], "Return pointer error");
}
