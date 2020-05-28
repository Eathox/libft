/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove_test.c                                  :+:    :+:            */
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
#define MAX (STEP * 20)

static void free_lengths(
	struct criterion_test_params *crp
)
{
	size_t	*lengths;

	lengths = crp->params;
    cr_free(lengths);
}

ParameterizedTestParameters(ft_memmove, general)
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

ParameterizedTest(size_t *len, ft_memmove, general)
{
	t_uint8		*result = calloc(*len, sizeof(*result));
	t_uint8		*expected = calloc(*len, sizeof(*expected));
	void		*return_ptr;

	cr_expect_neq(result, NULL);
	cr_expect_neq(expected, NULL);

	memset(expected, UCHAR_MAX, *len);

	return_ptr = ft_memmove(result, expected, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");

	free(result);
	free(expected);
}

ParameterizedTestParameters(ft_memmove, allign)
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

	size_t count = sizeof(lengths) / sizeof(*lengths);
	return cr_make_param_array(size_t, lengths, count);
}

ParameterizedTest(size_t *len, ft_memmove, allign)
{
	t_uint8 	result[*len];
	t_uint8 	expected[*len];
	void		*return_ptr;

	bzero(result, *len);
	memset(expected, UCHAR_MAX, *len);

	return_ptr = ft_memmove(result, expected, *len);
	cr_assert_arr_eq(result, expected, *len, "%zu", *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}

Test(ft_memmove, overlap)
{
	size_t	const	len = 3;
	t_uint8 		result[] = {UCHAR_MAX, 0x0, UCHAR_MAX};
	t_uint8 		expected[] = {0x0, UCHAR_MAX, UCHAR_MAX};
	void			*return_ptr;

	return_ptr = ft_memmove(&result, &result[1], 2);
	cr_assert_arr_eq(result, expected, len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}
