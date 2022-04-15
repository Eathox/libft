#include <unistd.h>

#include "serialize.h"

ssize_t ft_write_serialize(t_serialize *serialize) {
    ssize_t ret;

    if (serialize->use_buffer == false)
        return -1;
    ret = write(serialize->fd, serialize->content, serialize->content_size);
    return ret;
}
