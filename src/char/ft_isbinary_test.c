/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isbinary_test.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 11:59:04 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/28 11:59:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>

#include "char.h"

#define MAX CHAR_MAX
#define STEP 1

static bool isbinary(
	char c
) {
	return (c == '0' || c == '1');
}

Test(ft_isbinary, general) {
	size_t const	step = STEP;
	bool			expected;

	for (char c = 0x0; c < MAX; c += step) {
		expected = isbinary(c);
		cr_assert_eq(expected, ft_isbinary(c), "%d", c);
	}
}
