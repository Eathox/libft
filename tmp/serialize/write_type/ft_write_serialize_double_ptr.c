#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_double_ptr(t_serialize *serialize, double const *dbl_ptr, size_t size) {
    t_convert convert;

    convert.dbl_ptr = (double *)dbl_ptr;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
