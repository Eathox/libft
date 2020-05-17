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

t_color			ft_convert_hex_to_color(
	char const *hex
)
{
	t_color			color;
	const size_t	len = ft_strlen(hex);

	if (hex[0] != '#')
		return ((t_color){0, 0, 0, UCHAR_MAX});
	color.r = convert_hex_channel(&hex[1]);
	color.g = convert_hex_channel(&hex[3]);
	color.b = convert_hex_channel(&hex[5]);
	if (len == 9)
		color.a = convert_hex_channel(&hex[7]);
	else
		color.a = UCHAR_MAX;
	return (color);
}
