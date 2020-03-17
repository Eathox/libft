/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_endian.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 10:33:31 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/14 10:33:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"

t_endian	ft_get_endian(void)
{
	const t_uint32	i = 1;

	if (*((t_uint8*)&i) == 1)
		return (ENDIAN_LITTLE);
	return (ENDIAN_BIG);
}
