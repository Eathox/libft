/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_color_to_hex.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:19:30 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:19:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

#include "color.h"

#include "priv.h"

/*
** * Convert color struct to hex string data
** * Returns NULL if the allocation of the hex string failed
*/
char		*ft_convert_color_to_hex(
	t_color const *color,
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
	convert_byte_channel(&hex[1], color->r);
	convert_byte_channel(&hex[3], color->g);
	convert_byte_channel(&hex[5], color->b);
	if (include_alpha == true)
		convert_byte_channel(&hex[7], color->a);
	return (hex);
}
