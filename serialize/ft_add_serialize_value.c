/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_serialize_value.c                           :+:    :+:            */
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

static t_bool	expand_content(t_serialize *serialize, size_t current_size)
{
	t_uint8	*new_content;

	new_content = (t_uint8*)ft_memalloc(current_size + SERIALIZE_BUFF_SIZE);
	if (new_content == FALSE)
		return (FALSE);
	ft_memcpy(new_content, serialize->content, serialize->content_size);
	ft_memdel((void**)&serialize->content);
	serialize->content = new_content;
	return (TRUE);
}

static size_t	get_current_size(t_serialize *serialize)
{
	size_t	buff_size_amount;

	if (serialize->content_size == 0)
		return (0);
	buff_size_amount = (serialize->content_size - 1) / SERIALIZE_BUFF_SIZE;
	return ((buff_size_amount + 1) * SERIALIZE_BUFF_SIZE);
}

ssize_t			ft_add_serialize_value(t_serialize *serialize, t_uint8 *stream,
					size_t size)
{
	size_t	current_size;
	size_t	max_fit;
	size_t	fit;

	fit = size;
	if (serialize->use_buffer == FALSE)
		return (-1);
	current_size = get_current_size(serialize);
	if ((serialize->content_size + size) > current_size)
	{
		if (expand_content(serialize, current_size) == FALSE)
			return (-1);
		max_fit = SERIALIZE_BUFF_SIZE + current_size - serialize->content_size;
		if (fit > max_fit)
			fit = max_fit;
	}
	ft_memcpy(&serialize->content[serialize->content_size], stream, fit);
	serialize->content_size += fit;
	if (fit != size)
		return (ft_add_serialize_value(serialize, &stream[fit], size - fit));
	return (size);
}
