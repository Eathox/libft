#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int32_ptr(t_serialize *serialize, t_int32 **int32_ptr, size_t size) {
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int32_ptr = convert.int32_ptr;
    return ret;
}
