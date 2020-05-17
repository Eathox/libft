/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_hex_to_rgba_test.c                      :+:    :+:            */
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
#include <stdlib.h>
#include <stdbool.h>

#include <criterion/criterion.h>

#include "color.h"

static void	compare(
	t_uint32	rgba,
	char const	*hex
)
{
	char	result[10];

	sprintf(result, "#%02X%02X%02X%02X",
		(t_uint8)rgba,
		(t_uint8)(rgba >> 8),
		(t_uint8)(rgba >> 16),
		(t_uint8)(rgba >> 24)
	);
	cr_assert_str_eq(result, hex);
}

Test(ft_convert_hex_to_rgba, min)
{
	t_uint32 		rgba;
	char const		*hex = "#00000000";

	rgba = ft_convert_hex_to_rgba(hex);
	compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, max)
{
	t_uint32 		rgba;
	char const		*hex = "#FFFFFFFF";

	rgba = ft_convert_hex_to_rgba(hex);
	compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, 127)
{
	t_uint32 		rgba;
	char const		*hex = "#7F7F7F7F";

	rgba = ft_convert_hex_to_rgba(hex);
	compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, order)
{
	t_uint32 		rgba;
	char const		*hex = "#03020104";

	rgba = ft_convert_hex_to_rgba(hex);
	compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, segfault, .signal = SIGSEGV)
{
	t_uint32 		rgba;
	char const		*hex = NULL;

	rgba = ft_convert_hex_to_rgba(hex);
	compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, invalid)
{
	t_uint32 		rgba;
	char const		*hex = "hello world";

	rgba = ft_convert_hex_to_rgba(hex);
	compare(rgba, "#000000FF");
}

