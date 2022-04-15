#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int8(t_serialize *serialize, t_int8 *int8) {
    size_t const size = sizeof(t_int8);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int8 = *convert.int8_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
