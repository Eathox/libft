#include <stdio.h>
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

Test(convert_byte_channel, general) {
	char 	channel[3] = {0x0, 0x0, 0x0};

	for (t_uint8 byte_channel = 0x0; byte_channel < MAX; byte_channel += step)
	{
		convert_byte_channel(channel, byte_channel);
		compare(byte_channel, channel);
	}
}
