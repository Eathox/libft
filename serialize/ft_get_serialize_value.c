/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_serialize_value.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:29:29 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 00:29:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "serialize.h"
#include "priv.h"

ssize_t		ft_get_serialize_value(t_serialize *serialize, t_uint8 *result,
				size_t size)
{
	size_t	fit;
	size_t	max_fit;

	fit = size;
	if (serialize->use_buffer == FALSE)
		return (-1);
	if (serialize->content == NULL)
	{
		if (ft_read_serialize(serialize) < 0)
			return (-1);
	}
	if (serialize->content_pos > serialize->content_size)
		return (0);
	max_fit = serialize->content_size - serialize->content_pos;
	if (fit > max_fit)
		fit = max_fit;
	ft_memcpy(result, &serialize->content[serialize->content_pos], fit);
	serialize->content_pos += fit;
	return (fit);
}
