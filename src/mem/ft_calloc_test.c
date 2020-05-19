/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:37:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/18 19:37:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"

#include "mem.h"

#define FILL_MEMORY_COUNT 16
#define FILL_MEMORY_SIZE 24

static void	fill_memory(void)
{
	size_t		i;
	t_uint8		*holder[FILL_MEMORY_COUNT];

	i = 0;
	while (i < FILL_MEMORY_COUNT)
	{
		holder[i] = malloc(FILL_MEMORY_SIZE);
		cr_expect_neq(holder[i], NULL);

		memset(holder[i], 0xFF, FILL_MEMORY_SIZE);
		i++;
	}

	while (i > 0)
	{
		i--;
		free(holder[i]);
	}
}

typedef	struct	s_params
{
	size_t	size;
	size_t	count;
}				t_params;

ParameterizedTestParameters(ft_calloc, general)
{
	static t_params	size_count[] = {
		{1, 1},
		{8, 1},
		{1, 8},
		{8, 8},
		{3, 3},
	};

	size_t count = sizeof(size_count) / sizeof(t_params);
	return cr_make_param_array(t_params, size_count, count);
}

ParameterizedTest(t_params *params, ft_calloc, general, .init = fill_memory)
{
	size_t const	size = params->size;
	size_t const	count = params->count;
	t_uint8			*result;
	t_uint8			expected[size * count];

	result = ft_calloc(count, size);
	cr_expect_neq(result, NULL);

	bzero(expected, (size * count));
	cr_assert_arr_eq(result, expected, sizeof(expected), "%zu, %zu", size, count);

	free(result);
}

Test(ft_calloc, zero)
{
	size_t const	size = 0;
	size_t const	count = 0;
	t_uint8			*result;

	result = ft_calloc(count, size);
	cr_assert_eq(result, NULL);
}

Test(ft_calloc, zero_count)
{
	size_t const	size = 1;
	size_t const	count = 0;
	t_uint8			*result;

	result = ft_calloc(count, size);
	cr_assert_eq(result, NULL);
}

Test(ft_calloc, zero_size)
{
	size_t const	size = 0;
	size_t const	count = 1;
	t_uint8			*result;

	result = ft_calloc(count, size);
	cr_assert_eq(result, NULL);
}

Test(ft_calloc, overflow)
{
	size_t const	size = SIZE_MAX;
	size_t const	count = 2;
	t_uint8			*result;

	result = ft_calloc(count, size);
	cr_assert_eq(result, NULL);
}
