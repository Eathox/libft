/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_correct_endian.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 20:16:00 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 20:16:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "serialize.h"
#include "priv.h"

t_bool		ft_correct_endian(t_serialize *serialize, t_uint8 *stream,
				size_t size)
{
	if (ft_check_correct_endian(serialize, size) == FALSE)
		return (FALSE);
	ft_memrev(stream, size);
	return (TRUE);
}
