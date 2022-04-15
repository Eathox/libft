#include <ctype.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "../include/char.h"

#define MAX CHAR_MAX
#define STEP 1

Test(ft_isalnum, general) {
    size_t const step = STEP;
    char expected;

    for (char c = 0x0; c < MAX; c += step) {
        expected = isalnum(c);
        if (expected != 0)
            expected = true;
        cr_assert_eq(expected, ft_isalnum(c), "%d", c);
    }
}