#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int64_ptr(t_serialize *serialize, t_int64 **int64_ptr, size_t size) {
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int64_ptr = convert.int64_ptr;
    return ret;
}
