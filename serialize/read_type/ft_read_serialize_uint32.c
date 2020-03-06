/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_serialize_uint32.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster       #+#    #+#                */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_uint32(t_serialize *serialize, t_uint32 *uint32)
{
	size_t const	size = sizeof(t_uint32);
	t_convert		convert;
	ssize_t			ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*uint32 = *convert.uint32_ptr;
	return (ret);
}

