#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_int32_ptr(t_serialize *serialize, t_int32 const *int32_ptr, size_t size) {
    t_convert convert;

    convert.int32_ptr = (t_int32 *)int32_ptr;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
