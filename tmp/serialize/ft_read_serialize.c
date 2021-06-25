#include "ft/str.h"

#include "serialize.h"

#include "priv.h"

ssize_t		ft_read_serialize(t_serialize *serialize) {
	ssize_t	ret;

	if (serialize->use_buffer == false)
		return (-1);
	ft_clear_serialize(serialize);
	ret = ft_readfile(serialize->fd, (char **)&serialize->content);
	if (ret < 0)
		return (-1);
	serialize->content_size = ret;
	serialize->content_allocated_size = ret;
	return (ret);
}
