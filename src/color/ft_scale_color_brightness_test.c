/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_scale_color_brightness_test.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:09:22 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:09:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

Test(ft_scale_color_brightness, min)
{
	t_color 		result;
	t_color const	color = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
	t_color const	expected = {0x0, 0x0, 0x0, UCHAR_MAX};
	float const		brightness = 0;

	result = ft_scale_color_brightness(&color, brightness);
	cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_scale_color_brightness, max)
{
	t_color 		result;
	t_color const	color = {0x1, 0x1, 0x1, UCHAR_MAX};
	t_color const	expected = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
	float const		brightness = UCHAR_MAX;

	result = ft_scale_color_brightness(&color, brightness);
	cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_scale_color_brightness, 0x7F)
{
	t_color 		result;
	t_color const	color = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
	t_color const	expected = {0x7F, 0x7F, 0x7F, UCHAR_MAX};
	float const		brightness = 0.5;

	result = ft_scale_color_brightness(&color, brightness);
	cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_scale_color_brightness, order)
{
	t_color 		result;
	t_color const	color = {0x1, 0x2, 0x3, 0x4};
	t_color const	expected = color;
	float const		brightness = 1;

	result = ft_scale_color_brightness(&color, brightness);
	cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_scale_color_brightness, ratio)
{
	t_color 		result;
	t_color const	color = {0x0, 0x40, 0x10, UCHAR_MAX};
	t_color const	expected = {0x0, 0x80, 0x20, UCHAR_MAX};
	float const		brightness = 2;

	result = ft_scale_color_brightness(&color, brightness);
	cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}
