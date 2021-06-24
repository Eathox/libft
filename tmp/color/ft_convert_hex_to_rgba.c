/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_hex_to_rgba.c                           :+:    :+:            */
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
** * Convert hex string data to rgba byte data
** * Supports 6 and 8 character long hex strings
*/
t_uint32		ft_convert_hex_to_rgba(
	char const *hex
) {
	t_uint32		rgba;
	const size_t	len = ft_strlen(hex);

	if (hex[0] != '#')
		return (RGBA_ALPHA_MASK);
	rgba = 0x0;
	rgba |= convert_hex_channel(&hex[HEX_RED_INDEX]) << RGBA_RED_SHIFT;
	rgba |= convert_hex_channel(&hex[HEX_GREEN_INDEX]) << RGBA_GREEN_SHIFT;
	rgba |= convert_hex_channel(&hex[HEX_BLUE_INDEX]) << RGBA_BLUE_SHIFT;
	if (len == (HEX_ALPHA_INDEX + HEX_CHANNEL_SIZE))
		rgba |= convert_hex_channel(&hex[HEX_ALPHA_INDEX]) << RGBA_ALPHA_SHIFT;
	else
		rgba |= UCHAR_MAX << RGBA_ALPHA_SHIFT;
	return (rgba);
}
