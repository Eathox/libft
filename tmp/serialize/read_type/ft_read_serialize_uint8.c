#include "ft/mem.h"

#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_uint8(t_serialize *serialize, t_uint8 *uint8) {
	size_t const	size = sizeof(t_uint8);
	t_convert		convert;
	ssize_t			ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*uint8 = *convert.uint8_ptr;
	ft_memdel((void**)&convert.stream);
	return (ret);
}
