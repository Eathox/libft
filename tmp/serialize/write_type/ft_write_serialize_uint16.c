#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_uint16(t_serialize *serialize, t_uint16 uint16) {
	size_t const	size = sizeof(t_uint16);
	t_convert		convert;

	convert.uint16_ptr = &uint16;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
