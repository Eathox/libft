#include <unistd.h>

#include "thpool.h"

ssize_t ft_get_core_count(void) {
    return sysconf(_SC_NPROCESSORS_ONLN);
}
