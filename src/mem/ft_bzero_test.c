/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero_test.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:47:44 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"
#include "mem.h"

#define STEP 0x1
#define MAX CHAR_MAX

ParameterizedTestParameters(ft_bzero, allign) {
	static size_t	lengths[] = {
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
	t_uint32 		result[*len];
	t_uint8 		expected[*len];
	void			*return_ptr;

	bzero(expected, *len);
	return_ptr = ft_bzero(result, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}

Test(ft_bzero, general) {
	size_t const	step = STEP;
	t_uint8			*result;
	t_uint8			*expected;
	void			*return_ptr;

	for (size_t len = 1; len < MAX; len += step)
	{
		result = calloc(len, sizeof(t_uint8));
		expected = calloc(len, sizeof(t_uint8));

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
