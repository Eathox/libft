/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lseek_serialize.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 00:36:05 by pholster      #+#    #+#                 */
/*   Updated: 2020/03/06 00:36:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>

#include "serialize.h"
#include "priv.h"

static off_t	lseek_serialize(t_serialize *serialize, off_t offset,
					int whence) {
	if (whence == SEEK_SET) {
		if (offset < 0)
			return (-1);
		return (offset);
	}
	else if (whence == SEEK_CUR) {
		if (offset < 0 && serialize->pos < (size_t)-offset)
			return (-1);
		return (serialize->pos + offset);
	}
	else if (whence == SEEK_END) {
		if (offset < 0 && serialize->content_size < (size_t)-offset)
			return (-1);
		return (serialize->content_size + offset);
	}
	return (-1);
}

off_t			ft_lseek_serialize(t_serialize *serialize, off_t offset,
					int whence) {
	off_t	ret;

	if (serialize->use_buffer == true)
		ret = lseek_serialize(serialize, offset, whence);
	else
		ret = lseek(serialize->fd, offset, whence);
	if (ret >= 0)
		serialize->pos = ret;
	return (ret);
}
