/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:37:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/18 19:37:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>

#include "ft/types.h"
#include "mem.h"

#define STEP 0x1
#define MAX CHAR_MAX

#define CHARACTER_SIZE (sizeof(t_uint8) * 1)
#define CHARACTER_MAX UCHAR_MAX
#define CHARACTER_STEP 0x1

Test(ft_memcmp, general) {
	size_t const	step = STEP;
	t_uint8			*mem1_byte;
	t_uint8			*mem2_byte;
	int				expected;
	int				result;

	for (size_t len = 1; len < MAX; len += step)
	{
		mem1_byte = calloc(len, sizeof(*mem1_byte));
		mem2_byte = calloc(len, sizeof(*mem2_byte));

		cr_expect_neq(mem1_byte, NULL);
		cr_expect_neq(mem2_byte, NULL);
		mem1_byte[len - 1] = UCHAR_MAX;

		expected = memcmp(mem1_byte, mem2_byte, len);
		result = ft_memcmp(mem1_byte, mem2_byte, len);
		cr_assert_eq(expected, result, "%zu", len);

		expected = memcmp(mem2_byte, mem1_byte, len);
		result = ft_memcmp(mem2_byte, mem1_byte, len);
		cr_assert_eq(expected, result, "%zu", len);

		free(mem1_byte);
		free(mem2_byte);
	}
}

Test(ft_memcmp, character) {
	size_t const	len = CHARACTER_SIZE;
	size_t const	step = CHARACTER_STEP;
	size_t const	count = CHARACTER_MAX / step;
	t_uint8 		mem1_byte[CHARACTER_SIZE];
	t_uint8 		mem2_byte[CHARACTER_SIZE];
	int				expected;
	int				result;

	for (t_uint8 c = 0x0; c < CHARACTER_MAX; c += step)
	{
		mem1_byte[len - 1] = c;
		mem2_byte[len - 1] = step * (count / 2);

		expected = memcmp(mem1_byte, mem2_byte, len);
		result = ft_memcmp(mem1_byte, mem2_byte, len);
		cr_assert_eq(expected, result, "%02X", c);
	}
}
