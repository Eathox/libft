#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_float(t_serialize *serialize, float flt) {
    size_t const size = sizeof(float);
    t_convert convert;

    convert.flt_ptr = &flt;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
