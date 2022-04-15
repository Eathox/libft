#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

// TODO parameterize tests

Test(ft_convert_rgba_to_color, min) {
    t_color color;
    t_uint32 const rgba = 0x0;

    color = ft_convert_rgba_to_color(rgba);
    cr_assert_arr_eq(&color, &rgba, sizeof(t_color));
}

Test(ft_convert_rgba_to_color, max) {
    t_color color;
    t_uint32 const rgba = UINT_MAX;

    color = ft_convert_rgba_to_color(rgba);
    cr_assert_arr_eq(&color, &rgba, sizeof(t_color));
}

Test(ft_convert_rgba_to_color, 0x7F) {
    t_color color;
    t_uint32 const rgba = 0x7F7F7F7F;

    color = ft_convert_rgba_to_color(rgba);
    cr_assert_arr_eq(&color, &rgba, sizeof(t_color));
}

Test(ft_convert_rgba_to_color, order) {
    t_color color;
    t_uint32 const rgba = 0x04030201;

    color = ft_convert_rgba_to_color(rgba);
    cr_assert_arr_eq(&color, &rgba, sizeof(t_color));
}
