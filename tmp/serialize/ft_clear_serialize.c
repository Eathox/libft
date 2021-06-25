#include "ft/mem.h"

#include "serialize.h"

#include "priv.h"

void	ft_clear_serialize(t_serialize *serialize) {
	ft_memdel((void**)&serialize->content);
	serialize->content_allocated_size = 0;
	serialize->content_size = 0;
}
