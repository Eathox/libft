/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_valid_endian.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 20:19:28 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/04 20:19:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"

bool		ft_valid_endian(t_endian endian)
{
	if (endian <= ENDIAN_INVALID || endian >= ENDIAN_COUNT)
		return (false);
	return (true);
}
