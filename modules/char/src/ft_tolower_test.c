#include <ctype.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "../include/char.h"

#define MAX CHAR_MAX
#define STEP 1

Test(ft_tolower, general) {
	size_t const step = STEP;
	char expected;

	for (char c = 0x0; c < MAX; c += step) {
		expected = tolower(c);
		cr_assert_eq(expected, ft_tolower(c), "%d", c);
	}
}
