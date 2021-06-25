#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_float_ptr(t_serialize *serialize, float **flt_ptr,
				size_t size) {
	t_convert	convert;
	ssize_t		ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*flt_ptr = convert.flt_ptr;
	return (ret);
}
