/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex_channel_test.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 04:36:22 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/17 04:36:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "priv.h"

static void	compare(
	t_uint8	rgba_channel,
	char const	*channel
)
{
	char	result[3];

	sprintf(result, "%02X", rgba_channel);
	cr_assert_str_eq(result, channel);
}

Test(convert_hex_channel, min)
{
	t_uint8 		rgba_channel;
	char const		*channel = "00";

	rgba_channel = convert_hex_channel(channel);
	compare(rgba_channel, channel);
}

Test(convert_hex_channel, max)
{
	t_uint8 		rgba_channel;
	char const		*channel = "FF";

	rgba_channel = convert_hex_channel(channel);
	compare(rgba_channel, channel);
}

Test(convert_hex_channel, 127)
{
	t_uint8 		rgba_channel;
	char const		*channel = "7F";

	rgba_channel = convert_hex_channel(channel);
	compare(rgba_channel, channel);
}

