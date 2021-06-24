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
#include <string.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "priv.h"

#define MAX UCHAR_MAX
#define STEP 0x1

static void	compare(
	t_uint8	byte_channel,
	char const	*channel
) {
	char	result[3];

	sprintf(result, "%02X", byte_channel);
	cr_assert_str_eq(result, channel);
}

Test(convert_hex_channel, general) {
	size_t const	step = STEP;
	char const		*channel = calloc(3, sizeof(char));
	t_uint8 		byte_channel;
	t_uint8 		result;

	cr_expect_neq(channel, NULL);

	for (t_uint8 byte_channel = 0x0; byte_channel < MAX; byte_channel += step)
	{
		sprintf(channel, "%02X", byte_channel);

		result = convert_hex_channel(channel);
		compare(result, channel);
	}

	free(channel);
}
