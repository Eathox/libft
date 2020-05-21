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
#include <criterion/parameterized.h>

#include "priv.h"

#define MAX UCHAR_MAX
#define STEP 0x19

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
	char	**channels;
	size_t	i;

	i = 0;
	channels = crp->params;
	while (i < crp->length)
	{
		cr_free(channels[i]);
		i++;
	}
    cr_free(channels);
}

ParameterizedTestParameters(convert_hex_channel, general)
{
	size_t const	step = STEP;
	size_t const	count = (MAX / step);
	char 			**channels;
	char			*channel;
	t_uint8			byte_channel;
	size_t			i;

	channels = cr_calloc(count, sizeof(channel));
	cr_expect_neq(channels, NULL);

	i = 0;
	byte_channel = 0x0;
	while (i < count)
	{
		channel = cr_calloc(3, sizeof(char));
		cr_expect_neq(channel, NULL);

		sprintf(channel, "%02X", byte_channel);
		channels[i] = channel;
		byte_channel += step;
		i++;
	}
	return cr_make_param_array(char const *, channels, count, free_channels);
}

ParameterizedTest(char **channel, convert_hex_channel, general)
{
	t_uint8 	byte_channel;

	byte_channel = convert_hex_channel(*channel);
	compare(byte_channel, *channel);
}
