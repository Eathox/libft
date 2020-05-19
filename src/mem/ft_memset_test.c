/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:37:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/18 19:37:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"

#include "mem.h"

#define OVERFLOW_SIZE 32

#define CHARACTER_SIZE 1
#define CHARACTER_C_STEP 8

typedef	struct	s_params
{
	size_t	size;
	size_t	len;
	int	c;
}				t_params;

ParameterizedTestParameters(ft_memset, size_len)
{
	static t_params size_len[] = {
		{
			.size = 1,
			.len = 1,
			.c = 0xFF,
		},
		{
			.size = 8,
			.len = 1,
			.c = 0xFF,
		},
		{
			.size = 16,
			.len = 8,
			.c = 0xFF,
		},
		{
			.size = 64,
			.len = 31,
			.c = 0xFF,
		},
		{
			.size = 64,
			.len = 33,
			.c = 0xFF,
		},
		{
			.size = 64,
			.len = 64,
			.c = 0xFF,
		},
		{
			.size = 1024,
			.len = 1024,
			.c = 0xFF,
		},
	};

	size_t count = sizeof(size_len) / sizeof(t_params);
	return cr_make_param_array(t_params, size_len, count);
}

ParameterizedTest(t_params *params, ft_memset, size_len) {
	size_t const	size = params->size;
	size_t const	len = params->len;
	t_uint8			*result = calloc(1, size);
	t_uint8			*expected = calloc(1, size);

	cr_expect_neq(result, NULL);
	cr_expect_neq(expected, NULL);

	ft_memset(result, params->c, len);
	memset(expected, params->c, len);
	cr_assert_arr_eq(result, expected, size, "%zu, %zu", size, len);

	free(result);
	free(expected);
}

static void free_characters(
	struct criterion_test_params *crp
)
{
	int	*characters;

	characters = crp->params;
    cr_free(characters);
}

ParameterizedTestParameters(ft_memset, character)
{
	size_t const	step = CHARACTER_C_STEP;
	size_t const	count = (UCHAR_MAX + (step * 2)) / step;
	int 			*characters;
	int				c;
	size_t			i;

	characters = cr_calloc(count, sizeof(c));
	cr_expect_neq(characters, NULL);

	i = 0;
	c = 0x0;
	while (i < count)
	{
		characters[i] = c;
		c += step;
		i++;
	}
	return cr_make_param_array(int, characters, count, free_characters);
}

ParameterizedTest(int *c, ft_memset, character) {
	size_t const	size = CHARACTER_SIZE;
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		result[CHARACTER_SIZE];
	t_uint8 		expected[CHARACTER_SIZE];

	ft_memset(result, *c, len);
	memset(expected, *c, len);
	cr_assert_arr_eq(result, expected, size, "%X", *c);
}

Test(ft_memset, overflow, .signal = SIGSEGV)
{
	size_t const	size = OVERFLOW_SIZE;
	size_t const	len = size * 4;
	t_uint8			result[size];
	t_uint8			expected[size];

	memset(result, 0x0, size);
	memset(expected, 0x0, size);

	ft_memset(result, 0xFF, len);
	memset(expected, 0xFF, len);
	cr_assert_arr_eq(result, expected, size);
}
