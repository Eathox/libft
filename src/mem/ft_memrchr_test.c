/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr_test.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:37:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/18 19:37:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <string.h>

#include <criterion/criterion.h>

#include "ft/types.h"
#include "mem.h"

#define STEP 0x1
#define MAX ((STEP * 20) + 1)

#define CHARACTER_SIZE (sizeof(t_uint8) * 1)
#define CHARACTER_MAX UCHAR_MAX
#define CHARACTER_STEP 0x1

Test(ft_memrchr, general) {
	size_t const	step = STEP;
	size_t const	size = MAX;
	t_uint8			*mem_byte = calloc(size, sizeof(*mem_byte));
	t_uint8			*result;

	for (size_t index = 1; index < size; index += step) {
		cr_expect_neq(mem_byte, NULL);

		mem_byte[index - 0] = UCHAR_MAX;
		mem_byte[index - 1] = UCHAR_MAX;

		result = ft_memrchr(mem_byte, UCHAR_MAX, size);
		cr_assert_eq((size_t)index, (size_t)(result - mem_byte), "%zu", index);

		bzero(mem_byte, size);
	}
	free(mem_byte);
}

Test(ft_memrchr, character) {
	size_t const	step = CHARACTER_STEP;
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		mem_byte[CHARACTER_SIZE];
	t_uint8			*result;

	for (t_uint8 c = 0x0; c < CHARACTER_MAX; c += step) {
		mem_byte[len - 1] = c;

		result = ft_memrchr(mem_byte, c, len);
		cr_assert_eq((size_t)(len - 1), (size_t)(result - mem_byte), "%02X", c);
	}
}

Test(ft_memrchr, not_found) {
	size_t const	len = CHARACTER_SIZE;
	t_uint8 		mem_byte[CHARACTER_SIZE];
	t_uint8			*result;

	result = ft_memrchr(mem_byte, UCHAR_MAX, len);
	cr_assert_eq(result, NULL);
}
