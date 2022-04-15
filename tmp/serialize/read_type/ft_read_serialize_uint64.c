#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_uint64(t_serialize *serialize, t_uint64 *uint64) {
    size_t const size = sizeof(t_uint64);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *uint64 = *convert.uint64_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
