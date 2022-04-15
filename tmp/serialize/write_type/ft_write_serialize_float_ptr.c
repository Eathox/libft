#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_float_ptr(t_serialize *serialize, float const *flt_ptr, size_t size) {
    t_convert convert;

    convert.flt_ptr = (float *)flt_ptr;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
