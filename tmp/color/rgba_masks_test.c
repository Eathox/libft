#include <criterion/criterion.h>

#include "color.h"

Test(rgba_masks_test, order) {
    t_uint32 rgba;
    t_color const color = {
        .r = 0x1,
        .g = 0x2,
        .b = 0x3,
        .a = 0x4};

    rgba = ft_convert_color_to_rgba(&color);
    cr_assert_eq((rgba & RGBA_RED_MASK), 0x01 << RGBA_RED_SHIFT);
    cr_assert_eq((rgba & RGBA_GREEN_MASK), 0x02 << RGBA_GREEN_SHIFT);
    cr_assert_eq((rgba & RGBA_BLUE_MASK), 0x03 << RGBA_BLUE_SHIFT);
    cr_assert_eq((rgba & RGBA_ALPHA_MASK), 0x04 << RGBA_ALPHA_SHIFT);
}
