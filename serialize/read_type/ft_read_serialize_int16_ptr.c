/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_serialize_int16_ptr.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster       #+#    #+#                */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../serialize.h"
#include "../priv.h"

t_int16		*ft_read_serialize_int16_ptr(t_serialize *serialize, size_t size,
				ssize_t *ret)
{
	t_convert	convert;

	convert.stream = ft_read_serialize_value(serialize, size, ret);
	return (convert.int16_ptr);
}
