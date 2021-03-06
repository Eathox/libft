/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_serialize_write.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 19:34:04 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/03 19:34:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.h"

t_serialize		*ft_new_serialize_write(int fd, t_endian target_endian,
					bool use_buffer) {
	t_serialize *serialize;

	serialize = ft_new_serialize(target_endian, use_buffer);
	if (serialize == NULL)
		return (NULL);
	serialize->fd = fd;
	return (serialize);
}
