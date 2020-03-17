/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_serialize.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:17:09 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 00:17:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

#include "serialize.h"

#include "priv.h"

ssize_t		ft_read_serialize(t_serialize *serialize)
{
	ssize_t	ret;

	if (serialize->use_buffer == FALSE)
		return (-1);
	ft_clear_serialize(serialize);
	ret = ft_readfile(serialize->fd, (char **)&serialize->content);
	if (ret < 0)
		return (-1);
	serialize->content_size = ret;
	serialize->content_allocated_size = ret;
	return (ret);
}
