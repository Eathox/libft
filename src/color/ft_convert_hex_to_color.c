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

t_color			ft_convert_hex_to_color(
	char const *hex
)
{
	t_color			color;
	const size_t	len = ft_strlen(hex);

	color.r = convert_channel(&hex[0]);
	color.g = convert_channel(&hex[2]);
	color.b = convert_channel(&hex[4]);
	if (len == 8)
		color.a = convert_channel(&hex[6]);
	else
		color.a = UCHAR_MAX;
	return (color);
}
