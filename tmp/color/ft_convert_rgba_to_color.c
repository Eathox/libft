#include "color.h"

/*
** * Convert rgba byte data to color struct
*/
t_color ft_convert_rgba_to_color(
    t_uint32 rgba
) {
    t_color color;

    color.r = (t_uint8)(rgba >> RGBA_RED_SHIFT);
    color.g = (t_uint8)(rgba >> RGBA_GREEN_SHIFT);
    color.b = (t_uint8)(rgba >> RGBA_BLUE_SHIFT);
    color.a = (t_uint8)(rgba >> RGBA_ALPHA_SHIFT);
    return color;
}
