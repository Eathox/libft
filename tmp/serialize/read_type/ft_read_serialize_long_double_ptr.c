#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_long_double_ptr(t_serialize *serialize, long double **ldbl_ptr, size_t size) {
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *ldbl_ptr = convert.ldbl_ptr;
    return ret;
}
