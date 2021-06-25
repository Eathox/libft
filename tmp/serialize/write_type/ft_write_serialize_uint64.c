#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_uint64(t_serialize *serialize, t_uint64 uint64) {
	size_t const	size = sizeof(t_uint64);
	t_convert		convert;

	convert.uint64_ptr = &uint64;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
