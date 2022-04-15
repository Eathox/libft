#include "serialize.h"

t_serialize *ft_new_serialize_read(int fd, t_endian target_endian, bool use_buffer) {
    t_serialize *serialize;

    serialize = ft_new_serialize(target_endian, use_buffer);
    if (serialize == NULL)
        return NULL;
    serialize->fd = fd;
    return serialize;
}
