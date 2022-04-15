#include "color.h"
#include "ft/str.h"

#include "priv.h"

/*
** * Convert color struct to hex string data
** * Returns NULL if the allocation of the hex string failed
*/
char *ft_convert_color_to_hex(
    t_color const *color,
    bool include_alpha
) {
    char *hex;

    if (include_alpha == true)
        hex = ft_strnew(HEX_ALPHA_INDEX + HEX_CHANNEL_SIZE);
    else
        hex = ft_strnew(HEX_BLUE_INDEX + HEX_CHANNEL_SIZE);
    if (hex == NULL)
        return NULL;
    hex[0] = '#';
    convert_byte_channel(&hex[HEX_RED_INDEX], color->r);
    convert_byte_channel(&hex[HEX_GREEN_INDEX], color->g);
    convert_byte_channel(&hex[HEX_BLUE_INDEX], color->b);
    if (include_alpha == true)
        convert_byte_channel(&hex[HEX_ALPHA_INDEX], color->a);
    return hex;
}
