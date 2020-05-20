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

#define SIZE_LEN_MAX 512
#define SIZE_LEN_STEP 0xB

#define CHARACTER_SIZE (sizeof(t_uint8) * 2)
#define CHARACTER_STEP 0x7

typedef	struct	s_params
{
	size_t	size;
	size_t	len;
	t_uint8	c;
}				t_params;

static void free_size_len(
	struct criterion_test_params *crp
)
{
	t_params	*size_len;

	size_len = crp->params;
    cr_free(size_len);
}

ParameterizedTestParameters(ft_memset, size_len)
{
	size_t const	step = SIZE_LEN_STEP;
	size_t const	count = SIZE_LEN_MAX / step;
	t_params  		*size_len;
	t_params		param;
	size_t			i;

	size_len = cr_calloc(count, sizeof(param));
	cr_expect_neq(size_len, NULL);

	i = 0;
	param = (t_params){1, 1, UCHAR_MAX};
	while (i < count)
	{
		size_len[i] = param;
		param = (t_params){
			param.size + step,
			param.len + step,
			param.c
		};
		i++;
	}
	return cr_make_param_array(t_params, size_len, count, free_size_len);
}

ParameterizedTest(t_params *param, ft_memset, size_len)
{
	size_t const	size = param->size;
	size_t const	len = param->len;
	t_uint8			*result = calloc(size, sizeof(param->c));
	t_uint8			*expected = calloc(size, sizeof(param->c));
	void			*return_ptr;

	cr_expect_neq(result, NULL);
	cr_expect_neq(expected, NULL);

	memset(expected, param->c, len);
	return_ptr = ft_memset(result, param->c, len);
	cr_assert_arr_eq(result, expected, size, "%zu, %zu", size, len);
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
	size_t const	size = CHARACTER_SIZE;
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		result[CHARACTER_SIZE];
	t_uint8 		expected[CHARACTER_SIZE];
	void			*return_ptr;

	memset(expected, *c, len);
	return_ptr = ft_memset(result, *c, len);
	cr_assert_arr_eq(result, expected, size, "%X", *c);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}
