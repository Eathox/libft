/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_serialize_long_double_ptr.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster       #+#    #+#                */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_long_double_ptr(t_serialize *serialize,
				long double const *ldbl_ptr, size_t size)
{
	t_convert	convert;

	convert.ldbl_ptr = (long double*)ldbl_ptr;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
