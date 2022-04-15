#include "ft/char.h"

#include "priv.h"

/*
** * Convert a hex string color channel to t_uint8
*/
t_uint8 convert_hex_channel(
    char const *channel
) {
    const char *base_str = "0123456789ABCDEF";
    t_uint8 result;

    result = ft_chrindex(base_str, ft_toupper(channel[0]));
    result = (result * 16) + ft_chrindex(base_str, ft_toupper(channel[1]));
    return result;
}
