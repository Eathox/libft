#include <ctype.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "char.h"

#define MAX CHAR_MAX
#define STEP 1

Test(ft_toupper, general) {
	size_t const step = STEP;
	char expected;

	for (char c = 0x0; c < MAX; c += step) {
		expected = toupper(c);
		cr_assert_eq(expected, ft_toupper(c), "%d", c);
	}
}
