#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

// TODO parameterize tests

Test(ft_mix_color, min) {
    t_color const bg = {0x0, 0x0, 0x0, 0x0};
    t_color const fg = {0x0, 0x0, 0x0, 0x0};
    t_color const expected = bg;
    t_color result;

    result = ft_mix_color(&bg, &fg);
    cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_mix_color, max) {
    t_color const bg = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
    t_color const fg = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
    t_color const expected = bg;
    t_color result;

    result = ft_mix_color(&bg, &fg);
    cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_mix_color, 0x7F) {
    t_color const bg = {0x0, 0x0, 0x0, UCHAR_MAX};
    t_color const fg = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, 0x7F};
    t_color const expected = {0x7F, 0x7F, 0x7F, 0xBF};
    t_color result;

    result = ft_mix_color(&bg, &fg);
    cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_mix_color, full_fg) {
    t_color const bg = {0x0, 0x0, 0x0, UCHAR_MAX};
    t_color const fg = {UCHAR_MAX, UCHAR_MAX, UCHAR_MAX, UCHAR_MAX};
    t_color const expected = fg;
    t_color result;

    result = ft_mix_color(&bg, &fg);
    cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}

Test(ft_mix_color, empty_fg) {
    t_color const bg = {0x0, 0x0, 0x0, UCHAR_MAX};
    t_color const fg = {0x0, 0x0, 0x0, 0x0};
    t_color const expected = bg;
    t_color result;

    result = ft_mix_color(&bg, &fg);
    cr_assert_arr_eq(&result, &expected, sizeof(t_color));
}
