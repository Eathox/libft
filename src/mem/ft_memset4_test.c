/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset4_test.c                                   :+:    :+:            */
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

#define CHARACTER_SIZE (sizeof(t_uint32) * 1)
#define CHARACTER_MAX UINT_MAX
#define CHARACTER_STEP 0x0F0F0F0F

static void	compare(
	t_uint32 *mem,
	t_uint32 c,
	size_t len
)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		cr_assert_eq(mem[i], c, "%zu, %08X", len, c);
		i++;
	}
}

static void free_lengths(
	struct criterion_test_params *crp
)
{
	size_t	*lengths;

	lengths = crp->params;
    cr_free(lengths);
}

ParameterizedTestParameters(ft_memset4, general)
{
	size_t const	step = STEP;
	size_t const	count = (MAX / step);
	size_t	 		*lengths;
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

ParameterizedTest(size_t *len, ft_memset4, general)
{
	t_uint32 const	c = UINT_MAX;
	t_uint32		*result = calloc(*len, sizeof(c));
	void			*return_ptr;

	cr_expect_neq(result, NULL);

	return_ptr = ft_memset4(result, c, *len);
	compare(result, c, *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");

	free(result);
}

static void free_characters(
	struct criterion_test_params *crp
)
{
	t_uint32	*characters;

	characters = crp->params;
    cr_free(characters);
}

ParameterizedTestParameters(ft_memset4, character)
{
	size_t const	step = CHARACTER_STEP;
	size_t const	count = CHARACTER_MAX / step;
	t_uint32 		*characters;
	t_uint32		c;
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
	return cr_make_param_array(t_uint32, characters, count, free_characters);
}

ParameterizedTest(t_uint32 *c, ft_memset4, character)
{
	size_t const	len = CHARACTER_SIZE;
	t_uint32 		result[len];
	void			*return_ptr;

	return_ptr = ft_memset4(result, *c, len);
	compare(result, *c, len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}

ParameterizedTestParameters(ft_memset4, unrolling)
{
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

	size_t count = sizeof(lengths) / sizeof(size_t);
	return cr_make_param_array(size_t, lengths, count);
}

ParameterizedTest(size_t *len, ft_memset4, unrolling)
{
	t_uint32 const	c = UINT_MAX;
	t_uint32 		result[*len];
	void			*return_ptr;

	return_ptr = ft_memset4(result, c, *len);
	compare(result, c, *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}

Test(ft_memset4, order)
{
	size_t const	len = 64;
	t_uint32 const	c = 0x01020304;
	t_uint32 		result[len];
	void			*return_ptr;

	return_ptr = ft_memset4(result, c, len);
	compare(result, c, len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}
