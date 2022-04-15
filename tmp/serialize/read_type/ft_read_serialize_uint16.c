#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_uint16(t_serialize *serialize, t_uint16 *uint16) {
    size_t const size = sizeof(t_uint16);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *uint16 = *convert.uint16_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
