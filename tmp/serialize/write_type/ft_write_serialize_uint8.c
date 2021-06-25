#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_uint8(t_serialize *serialize, t_uint8 uint8) {
	size_t const	size = sizeof(t_uint8);
	t_convert		convert;

	convert.uint8_ptr = &uint8;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
