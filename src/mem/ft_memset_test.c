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

#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"

#include "mem.h"

#define MAX 512
#define STEP 0xB

#define CHARACTER_SIZE (sizeof(t_uint8) * 2)
#define CHARACTER_STEP 0x7

static void free_lengths(
	struct criterion_test_params *crp
)
{
	size_t	*lengths;

	lengths = crp->params;
    cr_free(lengths);
}

ParameterizedTestParameters(ft_memset, general)
{
	size_t const	step = STEP;
	size_t const	count = MAX / step;
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

ParameterizedTest(size_t *len, ft_memset, general)
{
	t_uint8	const	c = UCHAR_MAX;
	t_uint8			*result = calloc(*len, sizeof(c));
	t_uint8			*expected = calloc(*len, sizeof(c));
	void			*return_ptr;

	cr_expect_neq(result, NULL);
	cr_expect_neq(expected, NULL);

	memset(expected, c, *len);
	return_ptr = ft_memset(result, c, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");

	free(result);
	free(expected);
}

static void free_characters(
	struct criterion_test_params *crp
)
{
	t_uint8	*characters;

	characters = crp->params;
    cr_free(characters);
}

ParameterizedTestParameters(ft_memset, character)
{
	size_t const	step = CHARACTER_STEP;
	size_t const	count = UCHAR_MAX / step;
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

ParameterizedTest(t_uint8 *c, ft_memset, character)
{
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		result[len];
	t_uint8 		expected[len];
	void			*return_ptr;

	memset(expected, *c, len);
	return_ptr = ft_memset(result, *c, len);
	cr_assert_arr_eq(result, expected, len, "%X", *c);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}

ParameterizedTestParameters(ft_memset, unrolling)
{
	static size_t	lengths[] = {
		31,
		32,
		33,
		63,
		64,
		65,
	};

	size_t count = sizeof(lengths) / sizeof(size_t);
	return cr_make_param_array(size_t, lengths, count);
}

ParameterizedTest(size_t *len, ft_memset, unrolling)
{
	t_uint8 const	c = UCHAR_MAX;
	t_uint32 		result[*len];
	t_uint8 		expected[*len];
	void			*return_ptr;

	memset(expected, c, *len);
	return_ptr = ft_memset(result, c, *len);
	cr_assert_arr_eq(result, expected, *len, "%X", c);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}
