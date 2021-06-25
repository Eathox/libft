#include "ft/mem.h"

#include "serialize.h"
#include "priv.h"

t_serialize		*ft_new_serialize(t_endian target_endian, bool use_buffer) {
	t_serialize *serialize;

	serialize = (t_serialize*)ft_memalloc(sizeof(t_serialize));
	if (serialize == NULL)
		return (NULL);
	serialize->fd = DEFAULT_FD;
	serialize->endian = ft_get_endian();
	serialize->use_buffer = use_buffer;
	serialize->target_endian = target_endian;
	return (serialize);
}
