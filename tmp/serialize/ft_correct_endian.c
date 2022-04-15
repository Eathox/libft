#include "ft/mem.h"

#include "priv.h"
#include "serialize.h"

bool ft_correct_endian(t_serialize *serialize, t_uint8 *stream, size_t size) {
    if (ft_check_correct_endian(serialize, size) == false)
        return false;
    ft_memrev(stream, size);
    return true;
}
