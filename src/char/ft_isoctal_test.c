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
#include <criterion/parameterized.h>

#include "char.h"

#define MAX CHAR_MAX
#define STEP 1

static bool isoctal(
	char c
)
{
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5')
		return (true);
	return (c == '6' || c == '7');
}

static void free_characters(
	struct criterion_test_params *crp
)
{
	char	*characters;

	characters = crp->params;
    cr_free(characters);
}

ParameterizedTestParameters(ft_isoctal, general)
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

ParameterizedTest(char *c, ft_isoctal, general)
{
	cr_assert_eq(isoctal(*c), ft_isoctal(*c), "%d", *c);
}
