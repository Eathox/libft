/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arraydel_test.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:08:14 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "ft/types.h"
#include "mem.h"

#define MAX UCHAR_MAX
#define STEP 0x19

#define MEMBER_SIZE (sizeof(t_uint8) * 1)

static void compare(
	t_uint8 **array,
	size_t len,
	t_uint8 c
)
{
	t_uint8	expected[MEMBER_SIZE];
	size_t	i;

	i = 0;
	memset(expected, c, MEMBER_SIZE);
	while (i < (len - 1))
	{
		cr_assert_arr_eq(array[i], expected, MEMBER_SIZE, "%02X", c);
		i++;
	}
}

static void	fill_array(
	t_uint8 **array,
	size_t len
)
{
	size_t	i;

	i = 0;
	array[len - 1] = NULL;
	while (i < (len - 1))
	{
		array[i] = malloc(MEMBER_SIZE);
		cr_expect_neq(array[i], NULL);

		memset(array[i], UCHAR_MAX, MEMBER_SIZE);
		i++;
	}
}

static void	empty_member(
	void **member
)
{
	bzero(*member, MEMBER_SIZE);
}

static void free_lengths(
	struct criterion_test_params *crp
)
{
	size_t	*lengths;

	lengths = crp->params;
    cr_free(lengths);
}

ParameterizedTestParameters(ft_arraydel, null_function)
{
	size_t const	step = STEP;
	size_t const	count = MAX / step;
	size_t 			*lengths;
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

ParameterizedTest(size_t *len, ft_arraydel, null_function)
{
	t_uint8 **array = calloc(*len, sizeof(t_uint8*));
	t_uint8 **cpy = calloc(*len, sizeof(t_uint8*));

	cr_expect_neq(array, NULL);
	cr_expect_neq(cpy, NULL);

	fill_array(array, *len);
	memcpy(cpy, array, *len * sizeof(*array));

	ft_arraydel((void***)&array, NULL);
	cr_assert_eq(array, NULL);

	compare(cpy, *len, UCHAR_MAX);
	ft_arraydel((void***)&cpy, &ft_memdel);
}

ParameterizedTestParameters(ft_arraydel, general)
{
	size_t const	step = STEP;
	size_t const	count = MAX / step;
	size_t 			*lengths;
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

ParameterizedTest(size_t *len, ft_arraydel, general)
{
	t_uint8 **array = calloc(*len, sizeof(t_uint8*));
	t_uint8 **cpy = calloc(*len, sizeof(t_uint8*));

	cr_expect_neq(array, NULL);
	cr_expect_neq(cpy, NULL);

	fill_array(array, *len);
	memcpy(cpy, array, *len * sizeof(*array));

	ft_arraydel((void***)&array, &empty_member);
	cr_assert_eq(array, NULL);

	compare(cpy, *len, 0x0);
	ft_arraydel((void***)&cpy, &ft_memdel);
}

Test(ft_arraydel, null)
{
	ft_arraydel(NULL, NULL);
}

Test(ft_arraydel, null_content)
{
	void	**array;

	array = NULL;
	ft_arraydel(&array, &ft_memdel);
	cr_assert_eq(array, NULL);
}
