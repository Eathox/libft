/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_serialize_read.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 19:34:04 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/03 19:34:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"

t_serialize		*ft_new_serialize_read(int fd, t_endian target_endian,
					t_bool use_buffer)
{
	t_serialize *serialize;

	serialize = ft_new_serialize(target_endian, use_buffer);
	if (serialize == NULL)
		return (NULL);
	serialize->fd = fd;
	return (serialize);
}
