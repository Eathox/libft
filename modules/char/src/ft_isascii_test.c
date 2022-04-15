#include <ctype.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "../include/char.h"

#define MAX CHAR_MAX
#define MIN CHAR_MIN
#define SIZE (abs(MIN) + abs(MAX))
#define STEP 1

Test(ft_isascii, general) {
    size_t const step = STEP;
    char expected;

    for (char c = MIN; c < MAX; c += step) {
        expected = isascii(c);
        if (expected != 0)
            expected = true;
        cr_assert_eq(expected, ft_isascii(c), "%d", c);
    }
}
