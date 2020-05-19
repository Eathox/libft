/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_byte_channel_test.c                        :+:    :+:            */
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
#include <criterion/parameterized.h>

#include "priv.h"

#define STEP 8

static void	compare(
	t_uint8	byte_channel,
	char const	*channel
)
{
	char	result[3];

	sprintf(result, "%02X", byte_channel);
	cr_assert_str_eq(result, channel);
}

static void free_channels(
	struct criterion_test_params *crp
)
{
	t_uint8	*channels;

	channels = crp->params;
    cr_free(channels);
}

ParameterizedTestParameters(convert_byte_channel, general)
{
	size_t const	step = STEP;
	size_t const	count = UCHAR_MAX / step;
	t_uint8 		*channels;
	t_uint8			byte_channel;
	size_t			i;

	channels = cr_calloc(count, sizeof(byte_channel));
	cr_expect_neq(channels, NULL);

	i = 0;
	byte_channel = 0x0;
	while (i < count)
	{
		channels[i] = byte_channel;
		byte_channel += step;
		i++;
	}
	return cr_make_param_array(t_uint8, channels, count, free_channels);
}

ParameterizedTest(t_uint8 *byte_channel, convert_byte_channel, general)
{
	char 	channel[3] = {0x0, 0x0, 0x0};

	convert_byte_channel(channel, *byte_channel);
	compare(*byte_channel, channel);
}
