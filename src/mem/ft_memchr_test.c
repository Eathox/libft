/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr_test.c                                   :+:    :+:            */
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

#include "ft/types.h"
#include "mem.h"

#define STEP 0x19
#define MAX ((STEP * 20) + 1)

#define CHARACTER_SIZE (sizeof(t_uint8) * 1)
#define CHARACTER_MAX UCHAR_MAX
#define CHARACTER_STEP 0xD

static void free_indexes(
	struct criterion_test_params *crp
)
{
	size_t	*indexes;

	indexes = crp->params;
    cr_free(indexes);
}

ParameterizedTestParameters(ft_memchr, general)
{
	size_t const	step = STEP;
	size_t const	count = (MAX / step);
	size_t  		*indexes;
	size_t			index;
	size_t			i;

	indexes = cr_calloc(count, sizeof(index));
	cr_expect_neq(indexes, NULL);

	i = 0;
	index = 1;
	while (i < count)
	{
		indexes[i] = index;
		index += step;
		i++;
	}
	return cr_make_param_array(size_t, indexes, count, free_indexes);
}

ParameterizedTest(size_t *index, ft_memchr, general)
{
	size_t const	size = MAX;
	t_uint8			*mem_byte = calloc(size, sizeof(*mem_byte));
	t_uint8			*expected;
	t_uint8			*result;

	cr_expect_neq(mem_byte, NULL);
	mem_byte[*index - 0] = UCHAR_MAX;
	mem_byte[*index - 1] = UCHAR_MAX;

	expected = memchr(mem_byte, UCHAR_MAX, size);
	result = ft_memchr(mem_byte, UCHAR_MAX, size);
	cr_assert_eq(expected, result, "%zu", *index);

	free(mem_byte);
}

static void free_characters(
	struct criterion_test_params *crp
)
{
	t_uint8	*characters;

	characters = crp->params;
    cr_free(characters);
}

ParameterizedTestParameters(ft_memchr, character)
{
	size_t const	step = CHARACTER_STEP;
	size_t const	count = CHARACTER_MAX / step;
	t_uint8 		*characters;
	t_uint8			c;
	size_t			i;

	characters = cr_calloc(count, CHARACTER_SIZE);
	cr_expect_neq(characters, NULL);

	i = 0;
	c = 0x0;
	while (i < count)
	{
		characters[i] = c;
		c += step;
		i++;
	}
	return cr_make_param_array(t_uint8, characters, count, free_characters);
}

ParameterizedTest(t_uint8 *c, ft_memchr, character)
{
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		mem_byte[len];
	t_uint8			*expected;
	t_uint8			*result;

	mem_byte[len - 1] = *c;

	expected = memchr(mem_byte, *c, len);
	result = ft_memchr(mem_byte, *c, len);
	cr_assert_eq(expected, result, "%02X", *c);
}

Test(ft_memchr, not_found)
{
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		mem_byte[len];
	t_uint8			*result;

	result = ft_memrchr(mem_byte, UCHAR_MAX, len);
	cr_assert_eq(result, NULL);
}
