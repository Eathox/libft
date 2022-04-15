#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_uint32_ptr(t_serialize *serialize, t_uint32 const *uint32_ptr, size_t size) {
    t_convert convert;

    convert.uint32_ptr = (t_uint32 *)uint32_ptr;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
