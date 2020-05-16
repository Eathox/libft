/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_color_to_argb_test.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:19:27 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:19:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

Test(ft_convert_color_to_argb, min)
{
	t_color const	color = {0x0, 0x0, 0x0, 0x0};
	t_uint32		argb;

	argb = ft_convert_color_to_argb(color);
	cr_assert_arr_eq(&argb, &color, sizeof(t_color));
}

Test(ft_convert_color_to_argb, max)
{
	t_color const	color = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
	t_uint32		argb;

	argb = ft_convert_color_to_argb(color);
	cr_assert_arr_eq(&argb, &color, sizeof(t_color));
}

Test(ft_convert_color_to_argb, 127)
{
	t_color const	color = {0x7F, 0x7F, 0x7F, 0x7F};
	t_uint32		argb;

	argb = ft_convert_color_to_argb(color);
	cr_assert_arr_eq(&argb, &color, sizeof(t_color));
}

Test(ft_convert_color_to_argb, order)
{
	t_color const	color = {0x1, 0x2, 0x3, 0x4};
	t_uint32		argb;

	argb = ft_convert_color_to_argb(color);
	cr_assert_arr_eq(&argb, &color, sizeof(t_color));
}
