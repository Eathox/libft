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

#include "../types/types.h"
#include "mem.h"

#define STEP 0x1
#define MAX CHAR_MAX

#define CHARACTER_SIZE (sizeof(uint32_t) * 1)
#define CHARACTER_MAX UINT_MAX
#define CHARACTER_STEP 0x01010101

static void compare(
	uint32_t *mem,
	uint32_t c,
	size_t len
) {
	for (size_t i = 0; i < len; i++)
		cr_assert_eq(mem[i], c, "%zu, %08X", len, c);
}

Test(ft_memset4, general) {
	size_t const step = STEP;
	uint32_t const c = UINT_MAX;
	uint32_t *result;
	void *return_ptr;

	for (size_t len = 1; len < MAX; len += step) {
		result = calloc(len, sizeof(c));
		cr_expect_neq(result, NULL);

		return_ptr = ft_memset4(result, c, len);
		compare(result, c, len);
		cr_assert_eq(return_ptr, result, "Return pointer error");

		free(result);
	}
}

Test(ft_memset4, character) {
	size_t const step = CHARACTER_STEP;
	size_t const len = CHARACTER_SIZE;
	uint32_t result[CHARACTER_SIZE];
	void *return_ptr;

	for (uint32_t c = 0x0; c < CHARACTER_MAX; c += step) {
		return_ptr = ft_memset4(result, c, len);
		compare(result, c, len);
		cr_assert_eq(return_ptr, result, "Return pointer error");
	}
}

Test(ft_memset4, order) {
	size_t const len = 64;
	uint32_t const c = 0x01020304;
	uint32_t result[64];
	void *return_ptr;

	return_ptr = ft_memset4(result, c, len);
	compare(result, c, len);
	cr_assert_eq(return_ptr, result, "Return pointer error");
}
