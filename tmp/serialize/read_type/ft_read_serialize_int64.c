#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int64(t_serialize *serialize, t_int64 *int64) {
    size_t const size = sizeof(t_int64);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int64 = *convert.int64_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
