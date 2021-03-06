/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy_test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"
#include "mem.h"

#define STEP 0x1
#define MAX CHAR_MAX

#define ALIGN_SIZE 128

ParameterizedTestParameters(ft_memccpy, allign) {
	static size_t	indexes[] = {
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
	t_uint8 const	c = 0x7F;
	size_t const	size = ALIGN_SIZE;
	t_uint8 		result[ALIGN_SIZE];
	t_uint8 		expected[ALIGN_SIZE];
	void			*return_ptr;

	bzero(result, size);
	bzero(expected, size);

	expected[*index - 1] = c;
	memset(expected, UCHAR_MAX, *index - 1);

	return_ptr = ft_memccpy(result, expected, c, size);
	cr_assert_arr_eq(result, expected, size, "%zu", *index);
	cr_assert_eq(return_ptr, &result[*index], "Return pointer error");
}

Test(ft_memccpy, general) {
	t_uint8 const	c = 0x7F;
	size_t const	step = STEP;
	size_t const	size = MAX;
	t_uint8			*result = calloc(size, sizeof(*result));
	t_uint8			*expected = calloc(size, sizeof(*expected));
	void			*return_ptr;

	cr_expect_neq(result, NULL);
	cr_expect_neq(expected, NULL);

	for (size_t index = 1; index < size; index += step)
	{
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
