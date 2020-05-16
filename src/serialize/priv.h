/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   priv.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:25:50 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/04 00:25:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIV_H
# define PRIV_H

# include "serialize.h"

# define DEFAULT_FD -1

bool		ft_check_correct_endian(t_serialize *serialize, size_t size);
bool		ft_correct_endian(t_serialize *serialize, t_uint8 *stream,
				size_t size);

void		ft_clear_serialize(t_serialize *serialize);
ssize_t		ft_read_serialize(t_serialize *serialize);

ssize_t		ft_read_serialize_value(t_serialize *serialize, t_uint8 **result,
				size_t size);
ssize_t		ft_get_serialize_value(t_serialize *serialize, t_uint8 *result,
				size_t size);

ssize_t		ft_write_serialize_value(t_serialize *serialize, t_uint8 *stream,
				size_t size);
ssize_t		ft_add_serialize_value(t_serialize *serialize,
				t_uint8 const *stream, size_t size);

#endif
