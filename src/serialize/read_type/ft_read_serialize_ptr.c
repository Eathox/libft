/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_serialize_ptr.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster       #+#    #+#                */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../serialize.h"
#include "../priv.h"

ssize_t	ft_read_serialize_ptr(t_serialize *serialize, void **ptr, size_t size)
{
	t_convert	convert;
	ssize_t		ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*ptr = convert.ptr;
	return (ret);
}
