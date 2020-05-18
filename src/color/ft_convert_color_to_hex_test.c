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

#include "color.h"

Test(ft_convert_color_to_hex, min)
{
	t_color const	color = {0x0, 0x0, 0x0, 0x0};
	char 			*hex;

	hex = ft_convert_color_to_hex(&color, false);
	cr_assert_str_eq(hex, "#000000");
}

Test(ft_convert_color_to_hex, max)
{
	t_color const	color = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
	char 			*hex;

	hex = ft_convert_color_to_hex(&color, false);
	cr_assert_str_eq(hex, "#FFFFFF");
}

Test(ft_convert_color_to_hex, 0x7F)
{
	t_color const	color = {CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX};
	char 			*hex;

	hex = ft_convert_color_to_hex(&color, false);
	cr_assert_str_eq(hex, "#7F7F7F");
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
	cr_assert_str_eq(hex, "#01020304");
}
