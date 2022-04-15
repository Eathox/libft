#include "ft/unum.h"

#include "num.h"

size_t ft_numlen_base(intmax_t value, int base) {
    uintmax_t num;

    num = (value < 0 && base == 10) ? -value : value;
    return (ft_unumlen_base(num, base) + (value < 0 && base == 10));
}
