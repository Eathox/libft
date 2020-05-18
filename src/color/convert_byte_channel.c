/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_byte_channel.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/17 04:36:22 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/17 04:36:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"

#include "priv.h"

/*
** * Convert a byte data channel to dst
*/
void	convert_byte_channel
(
	char *dst,
	t_uint8 channel
)
{
	const char	*base_str = "0123456789ABCDEF";

	dst[0] = base_str[(channel / 16)];
	dst[1] = base_str[(channel % 16)];
}
