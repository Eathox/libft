#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

//TODO parameterize tests

Test(ft_convert_color_to_rgba, min) {
	t_color const	color = {0x0, 0x0, 0x0, 0x0};
	t_uint32		rgba;

	rgba = ft_convert_color_to_rgba(&color);
	cr_assert_arr_eq(&rgba, &color, sizeof(t_color));
}

Test(ft_convert_color_to_rgba, max) {
	t_color const	color = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
	t_uint32		rgba;

	rgba = ft_convert_color_to_rgba(&color);
	cr_assert_arr_eq(&rgba, &color, sizeof(t_color));
}

Test(ft_convert_color_to_rgba, 0x7F) {
	t_color const	color = {CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX};
	t_uint32		rgba;

	rgba = ft_convert_color_to_rgba(&color);
	cr_assert_arr_eq(&rgba, &color, sizeof(t_color));
}

Test(ft_convert_color_to_rgba, order) {
	t_color const	color = {
		.r = 0x1,
		.g = 0x2,
		.b = 0x3,
		.a = 0x4
	};
	t_uint32		rgba;

	rgba = ft_convert_color_to_rgba(&color);
	cr_assert_arr_eq(&rgba, &color, sizeof(t_color));
}
