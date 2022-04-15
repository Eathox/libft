#ifndef COLOR_H
#define COLOR_H

#include "ft/types.h"

#define RGBA_RED_SHIFT 00
#define RGBA_GREEN_SHIFT 010
#define RGBA_BLUE_SHIFT 020
#define RGBA_ALPHA_SHIFT 030

#define RGBA_RED_MASK 0x000000FF
#define RGBA_GREEN_MASK 0x0000FF00
#define RGBA_BLUE_MASK 0x00FF0000
#define RGBA_ALPHA_MASK 0xFF000000

#define HEX_CHANNEL_SIZE 2

#define HEX_RED_INDEX 1
#define HEX_GREEN_INDEX 3
#define HEX_BLUE_INDEX 5
#define HEX_ALPHA_INDEX 7

typedef struct s_color {
    t_uint8 r;
    t_uint8 g;
    t_uint8 b;
    t_uint8 a;
} t_color;

char *ft_convert_color_to_hex(
    t_color const *color,
    bool include_alpha
);

t_uint32 ft_convert_color_to_rgba(
    t_color const *color
);

t_color ft_mix_color(
    t_color const *bg,
    t_color const *fg
);

t_color ft_scale_color_brightness(
    t_color const *color,
    float brightness
);

t_color ft_convert_hex_to_color(
    char const *hex
);

t_uint32 ft_convert_hex_to_rgba(
    char const *hex
);

t_color ft_convert_rgba_to_color(
    t_uint32 rgba
);

char *ft_convert_rgba_to_hex(
    t_uint32 rgba,
    bool include_alpha
);

#endif
