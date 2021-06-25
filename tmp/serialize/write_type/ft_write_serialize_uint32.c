#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_uint32(t_serialize *serialize, t_uint32 uint32) {
	size_t const	size = sizeof(t_uint32);
	t_convert		convert;

	convert.uint32_ptr = &uint32;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
