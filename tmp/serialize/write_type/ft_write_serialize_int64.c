#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_int64(t_serialize *serialize, t_int64 int64) {
    size_t const size = sizeof(t_int64);
    t_convert convert;

    convert.int64_ptr = &int64;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
