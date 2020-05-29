/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum_test.c                                  :+:    :+:            */
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
#include <criterion/parameterized.h>

#include "char.h"

#define MAX CHAR_MAX
#define STEP 1

static void free_characters(
	struct criterion_test_params *crp
)
{
	char	*characters;

	characters = crp->params;
    cr_free(characters);
}

ParameterizedTestParameters(ft_isalnum, general)
{
	size_t const	step = STEP;
	size_t const	count = MAX / step;
	char 			*characters;
	char			c;
	size_t			i;

	characters = cr_calloc(count, sizeof(*characters));
	cr_expect_neq(characters, NULL);

	i = 0;
	c = 0x0;
	while (i < count)
	{
		characters[i] = c;
		c += step;
		i++;
	}
	return cr_make_param_array(char, characters, count, free_characters);
}

ParameterizedTest(char *c, ft_isalnum, general)
{
	int		expected;

	expected = isalnum(*c);
	if (expected != 0)
		expected = true;
	cr_assert_eq(expected, ft_isalnum(*c), "%d", *c);
}
