#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_uint64_ptr(t_serialize *serialize, t_uint64 const *uint64_ptr, size_t size) {
    t_convert convert;

    convert.uint64_ptr = (t_uint64 *)uint64_ptr;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
