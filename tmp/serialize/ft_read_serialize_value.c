#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#include "ft/mem.h"

#include "priv.h"
#include "serialize.h"

ssize_t ft_read_serialize_value(t_serialize *serialize, t_uint8 **result, size_t size) {
    ssize_t ret;

    if (size == 0)
        return 0;
    *result = (t_uint8 *)ft_memalloc(size);
    if (*result == NULL)
        return -1;
    if (serialize->use_buffer == true)
        ret = ft_get_serialize_value(serialize, *result, size);
    else
        ret = read(serialize->fd, *result, size);
    if (ret > 0) {
        serialize->pos += ret;
        ft_correct_endian(serialize, *result, ret);
    }
    return ret;
}
