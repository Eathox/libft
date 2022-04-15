#include "../priv.h"
#include "../serialize.h"

ssize_t ft_write_serialize_double(t_serialize *serialize, double dbl) {
    size_t const size = sizeof(double);
    t_convert convert;

    convert.dbl_ptr = &dbl;
    return ft_write_serialize_value(serialize, convert.stream, size);
}
