/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_open_serialize.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 19:16:15 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 19:16:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "serialize.h"
#include "priv.h"

t_bool	ft_open_serialize(t_serialize *serialize, char const *file, int flags,
			mode_t mode)
{
	int		ret;

	ret = open(file, flags, mode);
	if (ret < 0)
	{
		serialize->fd = DEFAULT_FD;
		return (FALSE);
	}
	serialize->fd = ret;
	return (TRUE);
}
