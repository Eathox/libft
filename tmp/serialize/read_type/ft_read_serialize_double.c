#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_double(t_serialize *serialize, double *dbl) {
    size_t const size = sizeof(double);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *dbl = *convert.dbl_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
