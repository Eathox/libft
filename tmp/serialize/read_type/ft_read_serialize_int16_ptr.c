#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int16_ptr(t_serialize *serialize, t_int16 **int16_ptr, size_t size) {
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int16_ptr = convert.int16_ptr;
    return ret;
}
