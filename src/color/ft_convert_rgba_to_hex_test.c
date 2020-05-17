/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_rgba_to_hex_test.c                      :+:    :+:            */
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

Test(ft_convert_rgba_to_hex, min)
{
	char const		*hex;
	t_uint32 const	rgba = 0x0;

	hex = ft_convert_rgba_to_hex(rgba, false);
	cr_assert_str_eq(hex, "#000000");
}

Test(ft_convert_rgba_to_hex, max)
{
	char const		*hex;
	t_uint32 const	rgba = UINT_MAX;

	hex = ft_convert_rgba_to_hex(rgba, false);
	cr_assert_str_eq(hex, "#FFFFFF");
}

Test(ft_convert_rgba_to_hex, 127)
{
	char const		*hex;
	t_uint32 const	rgba = 0x7F7F7F7F;

	hex = ft_convert_rgba_to_hex(rgba, false);
	cr_assert_str_eq(hex, "#7F7F7F");
}

Test(ft_convert_rgba_to_hex, order)
{
	char const		*hex;
	t_uint32 const	rgba = 0x04030201;

	hex = ft_convert_rgba_to_hex(rgba, true);
	cr_assert_str_eq(hex, "#01020304");
}
