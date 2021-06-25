#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_uint16_ptr(t_serialize *serialize,
				t_uint16 **uint16_ptr, size_t size) {
	t_convert	convert;
	ssize_t		ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*uint16_ptr = convert.uint16_ptr;
	return (ret);
}
