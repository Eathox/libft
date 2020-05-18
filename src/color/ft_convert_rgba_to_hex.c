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

#include "priv.h"

/*
** * Convert rgba byte data to hex string data
** * Returns NULL if the allocation of the hex string failed
*/
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
	convert_byte_channel(&hex[1], rgba >> RGBA_RED_SHIFT);
	convert_byte_channel(&hex[3], rgba >> RGBA_GREEN_SHIFT);
	convert_byte_channel(&hex[5], rgba >> RGBA_BLUE_SHIFT);
	if (include_alpha == true)
		convert_byte_channel(&hex[7], rgba >> RGBA_ALPHA_SHIFT);
	return (hex);
}
