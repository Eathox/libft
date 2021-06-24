/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isoctal_test.c                                  :+:    :+:            */
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

static bool isoctal(
	char c
) {
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5')
		return (true);
	return (c == '6' || c == '7');
}

Test(ft_isoctal, general) {
	size_t const step = STEP;
	bool expected;

	for (char c = 0x0; c < MAX; c += step) {
		expected = isoctal(c);
		if (expected != 0)
			expected = true;
		cr_assert_eq(expected, ft_isoctal(c), "%d", c);
	}
}
