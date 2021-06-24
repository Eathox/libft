/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_hex_to_color.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:19:24 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:19:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "ft/str.h"
#include "color.h"

#include "priv.h"

/*
** * Convert hex string data to color struct
** * Supports 6 and 8 character long hex strings
*/
t_color			ft_convert_hex_to_color(
	char const *hex
) {
	t_color			color;
	const size_t	len = ft_strlen(hex);

	if (hex[0] != '#')
		return ((t_color){0x0, 0x0, 0x0, UCHAR_MAX});
	color.r = convert_hex_channel(&hex[HEX_RED_INDEX]);
	color.g = convert_hex_channel(&hex[HEX_GREEN_INDEX]);
	color.b = convert_hex_channel(&hex[HEX_BLUE_INDEX]);
	if (len == (HEX_ALPHA_INDEX + HEX_CHANNEL_SIZE))
		color.a = convert_hex_channel(&hex[HEX_ALPHA_INDEX]);
	else
		color.a = UCHAR_MAX;
	return (color);
}
