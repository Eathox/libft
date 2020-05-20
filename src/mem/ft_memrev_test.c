/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrev_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:18:13 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"

#include "mem.h"

#define MAX UCHAR_MAX
#define STEP 0x9

static void	compare(
	t_uint8	*mem,
	size_t len
)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		cr_assert_eq(mem[i], (t_uint8)((len - 1) - i), "%zu", len);
		i++;
	}
}

static void	set_mem(
	t_uint8 *mem,
	size_t len
)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		mem[i] = i;
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

ParameterizedTestParameters(ft_memrev, general)
{
	size_t const	step = STEP;
	size_t const	count = (MAX / step) + 3;
	size_t 			*lengths;
	size_t			len;
	size_t			i;

	lengths = cr_calloc(count, sizeof(len));
	cr_expect_neq(lengths, NULL);

	i = 0;
	len = 1;
	while (i < count - 3)
	{
		lengths[i] = len;
		len += step;
		i++;
	}

	lengths[i + 0] = 31;
	lengths[i + 1] = 32;
	lengths[i + 2] = 33;
	return cr_make_param_array(size_t, lengths, count, free_lengths);
}

ParameterizedTest(size_t *len, ft_memrev, general)
{
	t_uint8			*result = calloc(*len, sizeof(t_uint8));
	void			*return_ptr;

	cr_expect_neq(result, NULL);
	set_mem(result, *len);

	return_ptr = ft_memrev(result, *len);
	compare(result, *len);
	cr_assert_eq(return_ptr, result, "Return pointer error");

	free(result);
}
