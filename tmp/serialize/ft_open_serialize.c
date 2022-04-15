#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "priv.h"
#include "serialize.h"

bool ft_open_serialize(t_serialize *serialize, char const *file, int flags, mode_t mode) {
    int ret;

    ret = open(file, flags, mode);
    if (ret < 0) {
        serialize->fd = DEFAULT_FD;
        return false;
    }
    serialize->fd = ret;
    serialize->pos = 0;
    return true;
}
