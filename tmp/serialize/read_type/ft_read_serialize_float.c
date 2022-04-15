#include "ft/mem.h"

#include "../priv.h"
#include "../serialize.h"

ssize_t ft_read_serialize_float(t_serialize *serialize, float *flt) {
    size_t const size = sizeof(float);
    t_convert convert;
    ssize_t ret;

    ret = ft_read_serialize_value(serialize, &convert.stream, size);
    *flt = *convert.flt_ptr;
    ft_memdel((void **)&convert.stream);
    return ret;
}
