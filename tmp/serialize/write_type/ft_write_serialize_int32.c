#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_int32(t_serialize *serialize, t_int32 int32) {
    size_t const size = sizeof(t_int32);
    t_convert convert;

    convert.int32_ptr = &int32;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
