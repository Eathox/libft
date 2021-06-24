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

#include "../types/types.h"
#include "mem.h"

#define STEP 0x1
#define MAX CHAR_MAX

static void compare(
	uint8_t *mem,
	size_t len
) {
	for (size_t i = 0; i < len; i++)
		cr_assert_eq(mem[i], (uint8_t)((len - 1) - i), "%zu", len);
}

static void set_mem(
	uint8_t *mem,
	size_t len
) {
	for (size_t i = 0; i < len; i++)
		mem[i] = i;
}

Test(ft_memrev, general) {
	size_t const step = STEP;
	uint8_t *result;
	void *return_ptr;

	for (size_t len = 1; len < MAX; len += step) {
		result = calloc(len, sizeof(uint8_t));
		cr_expect_neq(result, NULL);

		set_mem(result, len);

		return_ptr = ft_memrev(result, len);
		compare(result, len);
		cr_assert_eq(return_ptr, result, "Return pointer error");

		free(result);
	}
}
