/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_rgba_to_hex.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:17:37 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:17:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

#include "color.h"

static void	convert_channel(
	char *dst,
	t_uint8 channel
)
{
	const char	*base_str = "0123456789ABCDEF";

	dst[0] = base_str[(channel / 16)];
	dst[1] = base_str[(channel % 16)];
}

char		*ft_convert_rgba_to_hex(
	t_uint32 rgba,
	bool include_alpha
)
{
	char	*hex;

	if (include_alpha == true)
		hex = ft_strnew(9);
	else
		hex = ft_strnew(7);
	if (hex == NULL)
		return (NULL);
	hex[0] = '#';
	convert_channel(&hex[1], rgba);
	convert_channel(&hex[3], rgba >> 8);
	convert_channel(&hex[5], rgba >> 16);
	if (include_alpha == true)
		convert_channel(&hex[7], rgba >> 24);
	return (hex);
}
