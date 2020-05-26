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

#define MAX 512
#define STEP 0x19

#define CHARACTER_SIZE (sizeof(t_uint8) * 1)
#define CHARACTER_MAX UCHAR_MAX
#define CHARACTER_STEP 0xD

static void free_lengths(
	struct criterion_test_params *crp
)
{
	size_t	*lengths;

	lengths = crp->params;
    cr_free(lengths);
}

ParameterizedTestParameters(ft_memchr, general)
{
	size_t const	step = STEP;
	size_t const	count = (MAX / step);
	size_t  		*lengths;
	size_t			len;
	size_t			i;

	lengths = cr_calloc(count, sizeof(len));
	cr_expect_neq(lengths, NULL);

	i = 0;
	len = 1;
	while (i < count)
	{
		lengths[i] = len;
		len += step;
		i++;
	}
	return cr_make_param_array(size_t, lengths, count, free_lengths);
}

ParameterizedTest(size_t *len, ft_memchr, general)
{
	size_t const	size = MAX;
	t_uint8			*mem1_byte = calloc(size, sizeof(*mem1_byte));
	t_uint8			*expected;
	t_uint8			*result;

	cr_expect_neq(mem1_byte, NULL);
	mem1_byte[*len - 1] = UCHAR_MAX;

	expected = memchr(mem1_byte, UCHAR_MAX, size);
	result = ft_memchr(mem1_byte, UCHAR_MAX, size);
	cr_assert_eq(expected, result, "%zu", *len);

	free(mem1_byte);
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
	t_uint8 		mem1_byte[len];
	t_uint8			*expected;
	t_uint8			*result;

	mem1_byte[len - 1] = *c;

	expected = memchr(mem1_byte, *c, len);
	result = ft_memchr(mem1_byte, *c, len);
	cr_assert_eq(expected, result, "%02X", *c);
}

Test(ft_memchr, not_found)
{
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		mem1_byte[len];
	t_uint8			*expected;
	t_uint8			*result;

	expected = memchr(mem1_byte, UCHAR_MAX, len);
	result = ft_memchr(mem1_byte, UCHAR_MAX, len);
	cr_assert_eq(expected, result);
}
