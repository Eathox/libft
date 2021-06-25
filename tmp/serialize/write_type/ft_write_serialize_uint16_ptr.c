#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_uint16_ptr(t_serialize *serialize,
				t_uint16 const *uint16_ptr, size_t size) {
	t_convert	convert;

	convert.uint16_ptr = (t_uint16*)uint16_ptr;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
