#include "serialize.h"

bool ft_valid_endian(t_endian endian) {
    if (endian <= ENDIAN_INVALID || endian >= ENDIAN_COUNT)
        return false;
    return true;
}
