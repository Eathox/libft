#include "../serialize.h"
#include "../priv.h"

ssize_t		ft_read_serialize_double_ptr(t_serialize *serialize,
				double **dbl_ptr, size_t size) {
	t_convert	convert;
	ssize_t		ret;

	ret = ft_read_serialize_value(serialize, &convert.stream, size);
	*dbl_ptr = convert.dbl_ptr;
	return (ret);
}
