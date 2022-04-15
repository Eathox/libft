#include <limits.h>

#include "color.h"

/*
** * Mix 2 color structs together resulting in a new color struct
*/
t_color ft_mix_color(
    t_color const *bg,
    t_color const *fg
) {
    float alpha;
    t_color result;

    // Todo look throught other rgba mixing algorithms
    alpha = (float)fg->a / UCHAR_MAX;
    if (alpha == 0.0)
        return *bg;
    if (alpha == 1.0)
        return *fg;
    result.r = bg->r * (1.0 - alpha) + fg->r * alpha;
    result.g = bg->g * (1.0 - alpha) + fg->g * alpha;
    result.b = bg->b * (1.0 - alpha) + fg->b * alpha;
    result.a = bg->a - (bg->a - fg->a) * alpha;
    return result;
}
