/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_serialize_uint8_ptr.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_uint8_ptr(t_serialize *serialize,
				t_uint8 const *uint8_ptr, size_t size) {
	t_convert	convert;

	convert.uint8_ptr = (t_uint8*)uint8_ptr;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
