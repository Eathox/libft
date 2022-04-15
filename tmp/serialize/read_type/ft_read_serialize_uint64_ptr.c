#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_uint64_ptr(t_serialize *serialize, t_uint64 **uint64_ptr, size_t size) {
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *uint64_ptr = convert.uint64_ptr;
    return ret;
}
