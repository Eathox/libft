#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_int16(t_serialize *serialize, t_int16 *int16) {
    size_t const size = sizeof(t_int16);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *int16 = *convert.int16_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
