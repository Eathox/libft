#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_int8(t_serialize *serialize, t_int8 int8) {
	size_t const	size = sizeof(t_int8);
	t_convert		convert;

	convert.int8_ptr = &int8;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
