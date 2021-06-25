#include <limits.h>

#include <criterion/criterion.h>

#include "color.h"

//TODO parameterize tests

Test(ft_convert_rgba_to_hex, min) {
	char 			*hex;
	t_uint32 const	rgba = 0x0;

	hex = ft_convert_rgba_to_hex(rgba, false);
	cr_expect_neq(hex, NULL);

	cr_assert_str_eq(hex, "#000000");

	free(hex);
}

Test(ft_convert_rgba_to_hex, max) {
	char 			*hex;
	t_uint32 const	rgba = UINT_MAX;

	hex = ft_convert_rgba_to_hex(rgba, false);
	cr_expect_neq(hex, NULL);

	cr_assert_str_eq(hex, "#FFFFFF");

	free(hex);
}

Test(ft_convert_rgba_to_hex, 0x7F) {
	char 			*hex;
	t_uint32 const	rgba = 0x7F7F7F7F;

	hex = ft_convert_rgba_to_hex(rgba, false);
	cr_expect_neq(hex, NULL);

	cr_assert_str_eq(hex, "#7F7F7F");

	free(hex);
}

Test(ft_convert_rgba_to_hex, order) {
	char 			*hex;
	t_uint32 const	rgba = 0x04030201;

	hex = ft_convert_rgba_to_hex(rgba, true);
	cr_expect_neq(hex, NULL);

	cr_assert_str_eq(hex, "#01020304");

	free(hex);
}
