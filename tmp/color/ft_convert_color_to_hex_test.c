#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

#define MAX UCHAR_MAX
#define STEP 0x1

static void compare(
    char const *hex,
    t_color const *color
) {
    t_color result;

    result = ft_convert_hex_to_color(hex);
    cr_assert_arr_eq(&result, color, sizeof(t_color), "(%hhu %hhu %hhu %hhu)", color->r, color->g, color->b, color->a);
}

Test(ft_convert_color_to_hex, general) {
    size_t const step = STEP;
    size_t const count = MAX / step;
    t_color color;
    char *hex;

    color = (t_color){0x0, 0x0, 0x0, 0x0};
    for (size_t i = 0; i < count; i++) {
        hex = ft_convert_color_to_hex(&color, false);
        cr_expect_neq(hex, NULL);

        compare(hex, &color);

        free(hex);

        color = (t_color){
            color.r + step,
            color.g + step,
            color.b + step,
            color.a + step};
    }
}

Test(ft_convert_color_to_hex, order) {
    t_color const color = {
        .r = 0x1,
        .g = 0x2,
        .b = 0x3,
        .a = 0x4};
    char *hex;

    hex = ft_convert_color_to_hex(&color, true);
    cr_expect_neq(hex, NULL);

    cr_assert_str_eq(hex, "#01020304"); // TODO compare

    free(hex);
}
