#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_long_double(t_serialize *serialize, long double *ldbl) {
    size_t const size = sizeof(long double);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *ldbl = *convert.ldbl_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
