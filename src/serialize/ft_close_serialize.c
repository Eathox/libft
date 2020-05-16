/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_close_serialize.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 19:16:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/04 19:16:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "serialize.h"
#include "priv.h"

static bool	clear(t_serialize *serialize, int ret)
{
	ft_clear_serialize(serialize);
	serialize->fd = DEFAULT_FD;
	serialize->pos = 0;
	if (ret < 0)
		return (false);
	return (true);
}

bool			ft_close_serialize(t_serialize **serialize, bool free)
{
	int		ret;

	ret = close((*serialize)->fd);
	if (free == true)
		ft_del_serialize(serialize);
	else
		return (clear(*serialize, ret));
	return (true);
}
