/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr_test.c                                   :+:    :+:            */
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
#define MAX ((STEP * 20) + 1)

#define CHARACTER_SIZE (sizeof(t_uint8) * 1)
#define CHARACTER_MAX UCHAR_MAX
#define CHARACTER_STEP 0x1

Test(ft_memchr, general)
{
	size_t const	step = STEP;
	size_t const	size = MAX;
	t_uint8			*mem_byte = calloc(size, sizeof(*mem_byte));
	t_uint8			*expected;
	t_uint8			*result;

	cr_expect_neq(mem_byte, NULL);

	for (size_t index = 1; index < size; index += step)
	{
		mem_byte[index - 0] = UCHAR_MAX;
		mem_byte[index - 1] = UCHAR_MAX;

		expected = memchr(mem_byte, UCHAR_MAX, size);
		result = ft_memchr(mem_byte, UCHAR_MAX, size);
		cr_assert_eq(expected, result, "%zu", index);

		bzero(expected, size);
		bzero(result, size);
	}

	free(mem_byte);
}

Test(ft_memchr, character)
{
	size_t const	step = CHARACTER_STEP;
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		mem_byte[CHARACTER_SIZE];
	t_uint8			*expected;
	t_uint8			*result;
	for (t_uint8 c = 0x0; c < CHARACTER_MAX; c += step)
	{
		mem_byte[len - 1] = c;

		expected = memchr(mem_byte, c, len);
		result = ft_memchr(mem_byte, c, len);
		cr_assert_eq(expected, result, "%02X", c);
	}
}

Test(ft_memchr, not_found)
{
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		mem_byte[CHARACTER_SIZE];
	t_uint8			*result;

	result = ft_memrchr(mem_byte, UCHAR_MAX, len);
	cr_assert_eq(result, NULL);
}
