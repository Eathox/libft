/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_hex_to_color_test.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:19:30 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:19:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

static void	compare
(
	t_color	color,
	char const	*hex
)
{
	char	result[10];

	sprintf(result, "#%02X%02X%02X%02X",
		color.r,
		color.g,
		color.b,
		color.a
	);
	cr_assert_str_eq(result, hex);
}

Test(ft_convert_hex_to_color, min)
{
	t_color 		color;
	char const		*hex = "#00000000";

	color = ft_convert_hex_to_color(hex);
	compare(color, hex);
}

Test(ft_convert_hex_to_color, max)
{
	t_color 		color;
	char const		*hex = "#FFFFFFFF";

	color = ft_convert_hex_to_color(hex);
	compare(color, hex);
}

Test(ft_convert_hex_to_color, 0x7F)
{
	t_color 		color;
	char const		*hex = "#7F7F7F7F";

	color = ft_convert_hex_to_color(hex);
	compare(color, hex);
}

Test(ft_convert_hex_to_color, order)
{
	t_color 		color;
	char const		*hex = "#03020104";

	color = ft_convert_hex_to_color(hex);
	compare(color, hex);
}

Test(ft_convert_hex_to_color, segfault, .signal = SIGSEGV)
{
	t_color 		color;
	char const		*hex = NULL;

	color = ft_convert_hex_to_color(hex);
	compare(color, hex);
}

Test(ft_convert_hex_to_color, invalid)
{
	t_color 		color;
	char const		*hex = "hello world";

	color = ft_convert_hex_to_color(hex);
	compare(color, "#000000FF");
}

