/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_serialize_uint16.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_uint16(t_serialize *serialize, t_uint16 *uint16) {
	size_t const	size = sizeof(t_uint16);
	t_convert		convert;
	ssize_t			ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*uint16 = *convert.uint16_ptr;
	ft_memdel((void**)&convert.stream);
	return (ret);
}
