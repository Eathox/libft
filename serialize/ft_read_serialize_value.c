/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_serialize_value.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:29:29 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 00:29:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "ft/mem.h"

#include "serialize.h"
#include "priv.h"

ssize_t		ft_read_serialize_value(t_serialize *serialize, t_uint8 **result,
				size_t size)
{
	ssize_t	ret;

	*result = (t_uint8*)ft_memalloc(size);
	if (*result == NULL)
		return (-1);
	if (serialize->use_buffer == TRUE)
		ret = ft_get_serialize_value(serialize, *result, size);
	else
		ret = read(serialize->fd, *result, size);
	ft_correct_endian(serialize, *result, size);
	return (ret);
}
