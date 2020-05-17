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

#include "ft/char.h"
#include "ft/str.h"

#include "color.h"

static t_uint8	convert_channel(
	char const *channel
)
{
	const char	*base_str = "0123456789ABCDEF";
	t_uint8		result;

	result = ft_chrindex(base_str, ft_toupper(channel[0]));
	result = (result * 16) + ft_chrindex(base_str, ft_toupper(channel[1]));
	return (result);
}

t_uint32		ft_convert_hex_to_rgba(
	char const *hex
)
{
	t_uint32		rgba;
	const size_t	len = ft_strlen(hex);

	if (hex[0] != '#')
		return (0xFF000000);
	rgba = convert_channel(&hex[1]);
	rgba |= convert_channel(&hex[3]) << 8;
	rgba |= convert_channel(&hex[5]) << 16;
	if (len == 9)
		rgba |= convert_channel(&hex[7]) << 24;
	else
		rgba |= UCHAR_MAX << 24;
	return (rgba);
}
