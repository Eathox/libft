#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int8_ptr(t_serialize *serialize, t_int8 **int8_ptr, size_t size) {
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int8_ptr = convert.int8_ptr;
    return ret;
}
