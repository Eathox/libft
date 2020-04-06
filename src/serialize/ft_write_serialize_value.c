/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_serialize_value.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:29:29 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/04 00:29:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft/mem.h"

#include "serialize.h"
#include "priv.h"

static t_uint8	*correct_endian(t_uint8 *stream, size_t size, t_bool reverse)
{
	t_uint8	*data;

	if (reverse == TRUE)
	{
		data = ft_memdup(stream, size);
		if (data == NULL)
			return (NULL);
		ft_memrev(data, size);
		return (data);
	}
	return (stream);
}

ssize_t			ft_write_serialize_value(t_serialize *serialize,
					t_uint8 *stream, size_t size)
{
	ssize_t		ret;
	t_uint8		*data;
	t_bool		reverse;

	if (size == 0)
		return (0);
	reverse = ft_check_correct_endian(serialize, size);
	data = correct_endian(stream, size, reverse);
	if (data == NULL)
		return (-1);
	if (serialize->use_buffer == TRUE)
		ret = ft_add_serialize_value(serialize, data, size);
	else
		ret = write(serialize->fd, data, size);
	if (ret > 0)
		serialize->pos += ret;
	if (reverse == TRUE)
		ft_memdel((void**)&data);
	return (ret);
}
