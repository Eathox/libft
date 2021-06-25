#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_int16(t_serialize *serialize, t_int16 int16) {
	size_t const	size = sizeof(t_int16);
	t_convert		convert;

	convert.int16_ptr = &int16;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
