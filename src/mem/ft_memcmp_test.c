/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp_test.c                                   :+:    :+:            */
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

ParameterizedTestParameters(ft_memcmp, general)
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

ParameterizedTest(size_t *len, ft_memcmp, general)
{
	t_uint8			*mem1_byte = calloc(*len, sizeof(*mem1_byte));
	t_uint8			*mem2_byte = calloc(*len, sizeof(*mem2_byte));
	int				expected;
	int				result;

	cr_expect_neq(mem1_byte, NULL);
	cr_expect_neq(mem2_byte, NULL);
	mem1_byte[*len - 1] = UCHAR_MAX;

	expected = memcmp(mem1_byte, mem2_byte, *len);
	result = ft_memcmp(mem1_byte, mem2_byte, *len);
	cr_assert_eq(expected, result, "%zu", *len);

	expected = memcmp(mem2_byte, mem1_byte, *len);
	result = ft_memcmp(mem2_byte, mem1_byte, *len);
	cr_assert_eq(expected, result, "%zu", *len);

	free(mem1_byte);
	free(mem2_byte);
}

static void free_characters(
	struct criterion_test_params *crp
)
{
	t_uint8	*characters;

	characters = crp->params;
    cr_free(characters);
}

ParameterizedTestParameters(ft_memcmp, character)
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

ParameterizedTest(t_uint8 *c, ft_memcmp, character)
{
	size_t const	len = CHARACTER_SIZE;
	size_t const	step = CHARACTER_STEP;
	size_t const	count = CHARACTER_MAX / step;
	t_uint8 		mem1_byte[len];
	t_uint8 		mem2_byte[len];
	int				expected;
	int				result;

	mem1_byte[len - 1] = *c;
	mem2_byte[len - 1] = step * (count / 2);

	expected = memcmp(mem2_byte, mem1_byte, len);
	result = ft_memcmp(mem2_byte, mem1_byte, len);
	cr_assert_eq(expected, result, "%02X", *c);
}
