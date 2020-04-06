/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_serialize_double.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 00:49:56 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/05 00:49:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_double(t_serialize *serialize, double dbl)
{
	size_t const	size = sizeof(double);
	t_convert		convert;

	convert.dbl_ptr = &dbl;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
