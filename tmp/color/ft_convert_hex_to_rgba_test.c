#include <limits.h>
#include <signal.h>
#include <stdio.h>

#include <criterion/criterion.h>

#include "color.h"

// TODO parameterize tests

static void compare(
    t_uint32 rgba,
    char const *hex
) {
    char result[10];

    sprintf(result, "#%02X%02X%02X%02X", (t_uint8)(rgba >> RGBA_RED_SHIFT), (t_uint8)(rgba >> RGBA_GREEN_SHIFT), (t_uint8)(rgba >> RGBA_BLUE_SHIFT), (t_uint8)(rgba >> RGBA_ALPHA_SHIFT));
    cr_assert_str_eq(result, hex);
}

Test(ft_convert_hex_to_rgba, min) {
    t_uint32 rgba;
    char const *hex = "#00000000";

    rgba = ft_convert_hex_to_rgba(hex);
    compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, max) {
    t_uint32 rgba;
    char const *hex = "#FFFFFFFF";

    rgba = ft_convert_hex_to_rgba(hex);
    compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, 0x7F) {
    t_uint32 rgba;
    char const *hex = "#7F7F7F7F";

    rgba = ft_convert_hex_to_rgba(hex);
    compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, order) {
    t_uint32 rgba;
    char const *hex = "#03020104";

    rgba = ft_convert_hex_to_rgba(hex);
    compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, segfault, .signal = SIGSEGV) {
    t_uint32 rgba;
    char const *hex = NULL;

    rgba = ft_convert_hex_to_rgba(hex);
    compare(rgba, hex);
}

Test(ft_convert_hex_to_rgba, invalid) {
    t_uint32 rgba;
    char const *hex = "hello world";

    rgba = ft_convert_hex_to_rgba(hex);
    compare(rgba, "#000000FF");
}
