/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_close_serialize.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 19:16:15 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 19:16:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "serialize.h"
#include "priv.h"

t_bool		ft_close_serialize(t_serialize *serialize, t_bool free)
{
	int		ret;

	ret = close(serialize->fd);
	ft_clear_serialize(serialize);
	serialize->fd = DEFAULT_FD;
	serialize->pos = 0;
	if (free == TRUE)
	{
		ft_del_serialize(&serialize);
		return (TRUE);
	}
	if (ret < 0)
		return (FALSE);
	return (TRUE);
}
