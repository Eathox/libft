#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_long_double_ptr(t_serialize *serialize, long double const *ldbl_ptr, size_t size) {
    t_convert convert;

    convert.ldbl_ptr = (long double *)ldbl_ptr;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
