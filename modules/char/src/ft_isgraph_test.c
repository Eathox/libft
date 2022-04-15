#include <ctype.h>
#include <limits.h>

#include <criterion/criterion.h>

#include "../include/char.h"

#define MAX CHAR_MAX
#define STEP 1

Test(ft_isgraph, general) {
    size_t const step = STEP;
    int expected;

    for (char c = 0x0; c < MAX; c += step) {
        expected = isgraph(c);
        if (expected != 0)
            expected = true;
        cr_assert_eq(expected, ft_isgraph(c), "%d", c);
    }
}