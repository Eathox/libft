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

#define SIZE_LEN_MAX 512
#define SIZE_LEN_STEP 0xB

#define CHARACTER_SIZE (sizeof(t_uint32) * 2)
#define CHARACTER_STEP 0x07070707

static void	compare(
	t_uint32	*mem,
	t_uint32	c,
	size_t		size
)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		cr_assert_eq(mem[i], c, "%zu, %X", size, c);
		i++;
	}
}

typedef	struct	s_params
{
	size_t		size;
	size_t		len;
	t_uint32	c;
}				t_params;

static void free_size_len(
	struct criterion_test_params *crp
)
{
	t_params	*size_len;

	size_len = crp->params;
    cr_free(size_len);
}

ParameterizedTestParameters(ft_memset4, size_len)
{
	size_t const	step = SIZE_LEN_STEP;
	size_t const	count = SIZE_LEN_MAX / step;
	t_params 		*size_len;
	t_params		param;
	size_t			i;

	size_len = cr_calloc(count, sizeof(param));
	cr_expect_neq(size_len, NULL);

	i = 0;
	param = (t_params){0x0, 0x0, UINT_MAX};
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

ParameterizedTest(t_params *param, ft_memset4, size_len)
{
	size_t const	size = param->size;
	size_t const	len = param->len;
	t_uint32		*result = calloc(size, sizeof(param->c));

	cr_expect_neq(result, NULL);

	ft_memset4(result, param->c, len);
	compare(result, param->c, size);

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
	size_t const	count = UINT_MAX / step;
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
	size_t const	size = CHARACTER_SIZE;
	size_t const	len = CHARACTER_SIZE;
	t_uint32 		result[CHARACTER_SIZE];

	ft_memset4(result, *c, len);
	compare(result, *c, size);
}
