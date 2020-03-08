/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_serialize.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:17:09 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 00:17:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "serialize.h"

ssize_t		ft_write_serialize(t_serialize *serialize, t_bool close)
{
	ssize_t	ret;

	if (serialize->use_buffer == FALSE)
		return (-1);
	ret = write(serialize->fd, serialize->content, serialize->content_size);
	if (close == TRUE)
		ft_close_serialize(serialize);
	return (ret);
}
