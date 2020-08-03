/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:37:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/18 19:37:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"
#include "mem.h"

#define FILL_MEMORY_COUNT 16
#define FILL_MEMORY_SIZE 24

static void	fill_memory(void) {
	t_uint8		*holder[FILL_MEMORY_COUNT];

	for (size_t i = 0; i < FILL_MEMORY_COUNT; i++) {
		holder[i] = malloc(FILL_MEMORY_SIZE);
		cr_expect_neq(holder[i], NULL);

		memset(holder[i], UCHAR_MAX, FILL_MEMORY_SIZE);
	}

	for (size_t i = 0; i < FILL_MEMORY_COUNT; i++)
		free(holder[i]);
}

ParameterizedTestParameters(ft_memalloc, general) {
	static size_t	size[] = {
		1,
		8,
		9,
		64,
	};

	size_t count = sizeof(size) / sizeof(*size);
	return cr_make_param_array(size_t, size, count);
}

ParameterizedTest(size_t *size, ft_memalloc, general, .init = fill_memory) {
	t_uint8		*result;
	t_uint8		expected[*size];

	result = ft_memalloc(*size);
	cr_expect_neq(result, NULL);

	bzero(expected, *size);
	cr_assert_arr_eq(result, expected, *size, "%zu", *size);

	free(result);
}

Test(ft_memalloc, zero) {
	size_t const	size = 0;
	t_uint8			*result;

	result = ft_memalloc(size);
	cr_assert_eq(result, NULL);
}
