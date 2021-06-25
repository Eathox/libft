#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_long_double(t_serialize *serialize,
				long double ldbl_ptr) {
	size_t const	size = sizeof(double);
	t_convert		convert;

	convert.ldbl_ptr = &ldbl_ptr;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
