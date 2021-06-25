#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_uint8_ptr(t_serialize *serialize,
				t_uint8 **uint8_ptr, size_t size) {
	t_convert	convert;
	ssize_t		ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*uint8_ptr = convert.uint8_ptr;
	return (ret);
}
