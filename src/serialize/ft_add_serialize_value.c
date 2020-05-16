/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_serialize_value.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:29:29 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/04 00:29:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "serialize.h"
#include "priv.h"

static bool	expand_content(t_serialize *serialize, size_t target_size)
{
	t_uint8	*new_content;
	size_t	new_size;

	new_size = serialize->content_allocated_size + SERIALIZE_BUFF_SIZE;
	while (new_size < target_size)
		new_size += SERIALIZE_BUFF_SIZE;
	new_content = (t_uint8*)ft_memalloc(new_size);
	if (new_content == NULL)
		return (false);
	ft_memcpy(new_content, serialize->content, serialize->content_size);
	ft_memdel((void**)&serialize->content);
	serialize->content_allocated_size = new_size;
	serialize->content = new_content;
	return (true);
}

ssize_t			ft_add_serialize_value(t_serialize *serialize,
					t_uint8 const *stream, size_t size)
{
	size_t	target_size;

	if (serialize->use_buffer == false)
		return (-1);
	target_size = serialize->pos + size;
	if (target_size > serialize->content_allocated_size)
	{
		if (expand_content(serialize, target_size) == false)
			return (-1);
	}
	ft_memcpy(&serialize->content[serialize->pos], stream, size);
	if (target_size > serialize->content_size)
		serialize->content_size = target_size;
	return (size);
}
