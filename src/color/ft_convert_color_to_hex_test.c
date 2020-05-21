/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_color_to_hex_test.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:19:30 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:19:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "color.h"

#define MAX UCHAR_MAX
#define STEP 0x19

static void	compare(
	char const	*hex,
	t_color	const *color
)
{
	t_color	result;

	result = ft_convert_hex_to_color(hex);
	cr_assert_arr_eq(&result, color, sizeof(t_color), "(%hhu %hhu %hhu %hhu)",
		color->r,
		color->g,
		color->b,
		color->a
	);
}

static void free_colors(
	struct criterion_test_params *crp
)
{
	t_color	*colors;

	colors = crp->params;
    cr_free(colors);
}

ParameterizedTestParameters(ft_convert_color_to_hex, general)
{
	size_t const	step = STEP;
	size_t const	count = MAX / step;
	t_color 		*colors;
	t_color			color;
	size_t			i;

	colors = cr_calloc(count, sizeof(colors));
	cr_expect_neq(colors, NULL);

	i = 0;
	color = (t_color){0x0, 0x0, 0x0, 0x0};
	while (i < count)
	{
		colors[i] = color;
		color = (t_color){
			color.r + step,
			color.g + step,
			color.b + step,
			color.a + step
		};
		i++;
	}
	return cr_make_param_array(t_color, colors, count, free_colors);
}

ParameterizedTest(t_color *color, ft_convert_color_to_hex, general)
{
	char	*hex;

	hex = ft_convert_color_to_hex(color, false);
	cr_expect_neq(hex, NULL);

	compare(hex, color);

	free(hex);
}

Test(ft_convert_color_to_hex, order)
{
	t_color const	color = {
		.r = 0x1,
		.g = 0x2,
		.b = 0x3,
		.a = 0x4
	};
	char 			*hex;

	hex = ft_convert_color_to_hex(&color, true);
	cr_expect_neq(hex, NULL);

	cr_assert_str_eq(hex, "#01020304"); //TODO compare

	free(hex);
}
