#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_write_serialize_ptr(t_serialize *serialize, void const *ptr,
				size_t size) {
	t_convert	convert;

	convert.ptr = (void*)ptr;
	return (ft_write_serialize_value(serialize, convert.stream, size));
}
