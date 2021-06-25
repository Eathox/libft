#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_uint32_ptr(t_serialize *serialize,
				t_uint32 **uint32_ptr, size_t size) {
	t_convert	convert;
	ssize_t		ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*uint32_ptr = convert.uint32_ptr;
	return (ret);
}
