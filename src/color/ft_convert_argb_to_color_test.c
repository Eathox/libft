/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_argb_to_color_test.c                    :+:    :+:            */
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

Test(ft_convert_argb_to_color, min)
{
	t_color			color;
	t_uint32 const	argb = 0x0;

	color = ft_convert_argb_to_color(argb);
	cr_assert_arr_eq(&color, &argb, sizeof(t_color));
}

Test(ft_convert_argb_to_color, max)
{
	t_color			color;
	t_uint32 const	argb = UINT_MAX;

	color = ft_convert_argb_to_color(argb);
	cr_assert_arr_eq(&color, &argb, sizeof(t_color));
}

Test(ft_convert_argb_to_color, 127)
{
	t_color			color;
	t_uint32 const	argb = 0x7F7F7F7F;

	color = ft_convert_argb_to_color(argb);
	cr_assert_arr_eq(&color, &argb, sizeof(t_color));
}

Test(ft_convert_argb_to_color, order)
{
	t_color			color;
	t_uint32 const	argb = 0x01020304;

	color = ft_convert_argb_to_color(argb);
	cr_assert_arr_eq(&color, &argb, sizeof(t_color));
}
