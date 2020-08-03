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

#include "ft/types.h"
#include "mem.h"

#define MAX UCHAR_MAX
#define STEP 0x1

#define MEMBER_SIZE (sizeof(t_uint8) * 1)

static void compare(
	t_uint8 **array,
	size_t len,
	t_uint8 c
) {
	t_uint8	expected[MEMBER_SIZE];

	memset(expected, c, MEMBER_SIZE);
	for (size_t i = 0; i < (len - 1); i++)
		cr_assert_arr_eq(array[i], expected, MEMBER_SIZE, "%02X", c);
}

static void	fill_array(
	t_uint8 **array,
	size_t len
) {
	array[len - 1] = NULL;
	for (size_t i = 0; i < (len - 1); i++) {
		array[i] = malloc(MEMBER_SIZE);
		cr_expect_neq(array[i], NULL);

		memset(array[i], UCHAR_MAX, MEMBER_SIZE);
	}
}

static void	empty_member(
	void **member
) {
	bzero(*member, MEMBER_SIZE);
}

Test(ft_arraydel, null_function) {
	size_t const	step = STEP;
	t_uint8 		**array;
	t_uint8 		**cpy;

	for (size_t len = 1; len < MAX; len += step) {
		array = calloc(len, sizeof(t_uint8*));
		cpy = calloc(len, sizeof(t_uint8*));

		cr_expect_neq(array, NULL);
		cr_expect_neq(cpy, NULL);

		fill_array(array, len);
		memcpy(cpy, array, len * sizeof(*array));

		ft_arraydel((void***)&array, NULL);
		cr_assert_eq(array, NULL);

		compare(cpy, len, UCHAR_MAX);
		ft_arraydel((void***)&cpy, &ft_memdel);
	}
}

Test(ft_arraydel, general) {
	size_t const	step = STEP;
	t_uint8 		**array;
	t_uint8 		**cpy;

	for (size_t len = 1; len < MAX; len += step) {
		array = calloc(len, sizeof(t_uint8*));
		cpy = calloc(len, sizeof(t_uint8*));

		cr_expect_neq(array, NULL);
		cr_expect_neq(cpy, NULL);

		fill_array(array, len);
		memcpy(cpy, array, len * sizeof(*array));

		ft_arraydel((void***)&array, &empty_member);
		cr_assert_eq(array, NULL);

		compare(cpy, len, 0x0);
		ft_arraydel((void***)&cpy, &ft_memdel);
	}
}

Test(ft_arraydel, null) {
	ft_arraydel(NULL, NULL);
}

Test(ft_arraydel, null_content) {
	void	**array;

	array = NULL;
	ft_arraydel(&array, &ft_memdel);
	cr_assert_eq(array, NULL);
}
