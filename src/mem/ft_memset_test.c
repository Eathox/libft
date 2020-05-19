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
#define SIZE_LEN_STEP 11

#define CHARACTER_SIZE 1
#define CHARACTER_C_STEP 7

typedef	struct	s_params
{
	size_t	size;
	size_t	len;
	int	c;
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
	t_params 		*size_len;
	t_params		param;
	size_t			i;

	size_len = cr_calloc(count, sizeof(param));
	cr_expect_neq(size_len, NULL);

	i = 0;
	param = (t_params){0x0, 0x0, 0xFF};
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

ParameterizedTest(t_params *params, ft_memset, size_len)
{
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
	size_t const	count = UCHAR_MAX / step;
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

ParameterizedTest(int *c, ft_memset, character)
{
	size_t const	size = CHARACTER_SIZE;
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		result[CHARACTER_SIZE];
	t_uint8 		expected[CHARACTER_SIZE];

	ft_memset(result, *c, len);
	memset(expected, *c, len);
	cr_assert_arr_eq(result, expected, size, "%X", *c);
}
