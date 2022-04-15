#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int32(t_serialize *serialize, t_int32 *int32) {
    size_t const size = sizeof(t_int32);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int32 = *convert.int32_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
