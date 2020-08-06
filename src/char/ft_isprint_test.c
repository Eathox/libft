/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint_test.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 11:59:04 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/28 11:59:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "char.h"

#define MAX CHAR_MAX
#define STEP 1

Test(ft_isprint, general) {
	size_t const	step = STEP;
	char			expected;

	for (char c = 0x0; c < MAX; c += step)
	{
		expected = isprint(c);
		if (expected != 0)
			expected = true;
		cr_assert_eq(expected, ft_isprint(c), "%d", c);
	}
}
