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

#include <string.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"

#include "mem.h"

#define MAX 512
#define STEP 0xB

static void free_lengths(
	struct criterion_test_params *crp
)
{
	size_t	*lengths;

	lengths = crp->params;
    cr_free(lengths);
}

ParameterizedTestParameters(ft_bzero, general)
{
	size_t const	step = STEP;
	size_t const	count = MAX / step;
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

ParameterizedTest(size_t *len, ft_bzero, general)
{
	t_uint8			*result = calloc(*len, sizeof(t_uint8));
	t_uint8			*expected = calloc(*len, sizeof(t_uint8));
	void			*return_ptr;

	cr_expect_neq(result, NULL);
	cr_expect_neq(expected, NULL);

	bzero(expected, *len);
	return_ptr = ft_bzero(result, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");

	free(result);
	free(expected);
}

ParameterizedTestParameters(ft_bzero, unrolling)
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

ParameterizedTest(size_t *len, ft_bzero, unrolling)
{
	t_uint32 		result[*len];
	t_uint8 		expected[*len];
	void			*return_ptr;

	bzero(expected, *len);
	return_ptr = ft_bzero(result, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}
