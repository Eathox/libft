/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_serialize_uint64.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster       #+#    #+#                */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../serialize.h"
#include "../priv.h"

t_uint64	ft_read_serialize_uint64(t_serialize *serialize, ssize_t *ret)
{
	size_t const	size = sizeof(t_uint64);
	t_convert		convert;

	convert.stream = ft_read_serialize_value(serialize, size, ret);
	return (*convert.uint64_ptr);
}
